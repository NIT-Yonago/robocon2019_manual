#include <Arduino.h>
#include "gyro_integral.h"

gyro_integral::gyro_integral(void)
{
}
void gyro_integral::init(int setup_count) //ジャイロ初期化（オフセット計算回数）
{
    Wire.begin();     //I2C開始
    if (!gyro.init()) //ジャイロか稼働するまで待機
    {
        Serial.println("Failed to autodetect gyro type!");
        while (1)
            ;
    }
    gyro.enableDefault(); //250deg/s,190Hz DR,50Hz BW
    // last_time = micros();                 //過去時間更新//下でしてるので削除
    long sum = 0;                         //合計初期化
    for (int i = 0; i < setup_count; i++) //オフセット計算回数ループ
    {
        gyro.read();     //ジャイロ読み
        sum += gyro.g.z; //合計に＋
        delay(6);        //ちょい待つ
    }
    gyro_offset = sum / setup_count; //オフセットの平均産出
    last_time = micros();            //過去時間更新
}
void gyro_integral::integral() //ジャイロ積分
{
    gyro.read();                                                     //ジャイロの値読み
    unsigned long now = micros();                                    //現在時
    int dt = now - last_time;                                        //経過時間
    last_time = now;                                                 //過去の時間更新
    gyro_val = gyro_val * 0.9 + ((int)gyro.g.z - gyro_offset) * 0.1; //ローパスフィルタ
    robot_angle += gyro_val * dt * 0.00875 / 1000000.0;              //角度を積分
}
void gyro_integral::print_gyro_data() //ジャイロデータ表示
{
    Serial.print((int)gyro.g.z * 0.00875); //各速度deg/s
    Serial.print(",");                     //
    Serial.print(gyro_val * 0.00875);      //LPFした各速度deg/s
    Serial.print(",");                     //
    Serial.println(robot_angle);           //現在角度
}
