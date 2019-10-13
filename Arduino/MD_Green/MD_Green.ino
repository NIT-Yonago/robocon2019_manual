//Morita Daiki 2019 @NIT.yonago
//2019/09/25
//Arduino Nano (old etc..)
//Black Motor Driver &インチキエアー
// #include <serial_communication_v0.h>
#include "PwmMotor.h"
#include "gyro_integral.h"

const int air_pin[3] = {A1, A2, A3}; //上下，前後，つかむ
boolean air_state[3];                //現在のエア状態
int speed[3];                        //モータ速度

unsigned long serial_tim_last = 0, gyro_tim_last = 0; //ループ監視用時間保持変数
boolean sta13 = false, enkaige = false;               //LED状態，宴会芸（回転補正）フラグ
float want_deg = 0, rot = 0.0, error_angle = 0.0;     //目標角，回転成分,角度誤差
int vx, vy, vrot, vrot_old;                           //X速度，Y速度，旋回速度，過去旋回速度

PwmMotor motor[3] = {
    //cw,ccw,pwm
    PwmMotor(4, 2, 3),
    PwmMotor(7, 5, 6),
    PwmMotor(A0, 8, 9),
};
gyro_integral gyro_1; //ジャイロセンサの名前

void setup() //初期設定
{
    for (int i = 0; i < 3; i++)
        pinMode(air_pin[i], OUTPUT);                //出力に設定
    pinMode(13, OUTPUT);                            //LED Pin
    Serial.begin(115200);                           //hunging_systemとの通信速度を変更
    Serial.println("tim,want,jsx,d/s,fild/s,angl"); //index print
    gyro_1.init(500);                               //ジャイロ初期オフセット計算（５００回）
}

void loop() //メインループ
{
    if ((millis() - gyro_tim_last) > 4) //4ms以上経過したら積分
    {
        gyro_1.integral();        //積分
        gyro_tim_last = millis(); //時間更新
        Serial.print(vx);
        Serial.print(",");
        Serial.print(vy);
        Serial.print(",");
        Serial.print(vrot);
        Serial.print(",");
        Serial.print(want_deg);
        Serial.print(",");
        Serial.println(gyro_1.robot_angle);
    }

    if ((millis() - serial_tim_last) > 1000) //操縦が長らくないときリセット
        reset();

    if (Serial.available() > 0) //シリアル受信時
    {
        if (Serial.read() == 0xff) //ヘッダなら
        {
            digitalWrite(13, sta13); //LEDちかちか
            sta13 = !sta13;          //LEDちかちか

            uint8_t read_data[4];           //受信データ
            Serial.readBytes(read_data, 4); //受信
            serial_tim_last = millis();     //シリアルの受信時間更新

            vx = read_data[0] - 31;      //-31~32
            vy = read_data[1] - 31;      //-31~32
            vrot = -(read_data[2] - 15); //-15~16
            air_move(read_data[3]);
        }
    }

    error_angle = want_deg - gyro_1.robot_angle;   //誤差
    rot = constrain(error_angle * 4.0, -255, 255); //誤差補正出力
    if (vrot == 0)                                 //JSが原点に戻った時
    {
        if (vrot_old != 0)                 //もともと旋回希望なら
            want_deg = gyro_1.robot_angle; //それを目標角度にする
    }
    else                 //その他
        rot = vrot * 15; //JSが操作中は旋回速度を指定
    if ((abs(vx) + abs(vy)) < 5 && abs(vrot) < 2)
    {
        if (!enkaige)
            rot = 0;
    }
    omni(vx, vy, rot); //速度出力

    vrot_old = vrot; //かこJS更新
}

void air_move(uint8_t air_cmd) //0:上下,1:前後,2:爪
{
    if ((air_cmd >> 3) & 1) //👆
        air_state[0] = true;
    else if ((air_cmd >> 4) & 1) //👇
        air_state[0] = false;

    if ((air_cmd >> 1) & 1) //前
        air_state[1] = true;
    else if ((air_cmd >> 2) & 1) //後
        air_state[1] = false;

    if ((air_cmd >> 0) & 1)           //爪開閉
        air_state[2] = !air_state[2]; //切り替え可能

    if ((air_cmd >> 5) & 1) //x&HOME
    {
        reset();          //全初期化
        gyro_1.init(500); //ジャイロ初期化
    }
    if ((air_cmd >> 6) & 1) //y
        enkaige = true;
    else
        enkaige = false;

    for (int i = 0; i < 3; i++)
        digitalWrite(air_pin[i], air_state[i]);
}

void omni(int vx, int vy, float vtheta)
{
    float v = sqrt(vx * vx + vy * vy) * 4.0; //速度は半径＊４
    float theta = atan2(vy, vx);             //方向はatan^-1(y/x)
    float R[3] = {1.0, 1.0, 1.0};            //ロボットのタイヤ配置（中心に近いと回転速度低下）
    for (int i = 0; i < 3; i++)              //各モータに対して．
        speed[i] = -v * cos(theta + PI - PI * 2.0 / 3.0 * i) - vtheta * R[i];
    int max = 255;              //最大値（仮）
    for (int i = 0; i < 3; i++) //最大値更新
        max = max(abs(speed[i]), max);
    for (int i = 0; i < 3; i++) //各モータに対して．
    {
        speed[i] = map(speed[i], -max, max, -255, 255); //更新した最大値で正規化
        motor[i].speed(speed[i]);                       //モーター回転
    }
}

void reset() //リセット
{
    vx = 0;                   //速度0
    vy = 0;                   //速度0
    vrot = 0;                 //旋回０
    vrot_old = 0;             //過去旋回０
    omni(0, 0, 0);            //スピードオフ
    want_deg = 0.0;           //目標リセット
    gyro_1.robot_angle = 0.0; //ロボット角度リセット
}
