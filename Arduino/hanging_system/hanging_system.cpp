#include "hanging_system.h"
#include <Arduino.h>

hanging_system::hanging_system(uint8_t spp_pin, uint8_t spm_pin, uint8_t air_pin, unsigned int deg_pdef, unsigned int deg_mdef, unsigned int t1, unsigned int t2, unsigned int tc)
{
    pinMode(air_pin, OUTPUT); //出力
    spp.attach(spp_pin);      //サーボ初期化
    spm.attach(spm_pin);      //サーボ初期化
    spp.write(deg_pdef);      //サーボ初期位置
    spm.write(deg_mdef);      //サーボ初期位置
    supply_start_time = millis();
    // delay(500);
    // spp.detach();
    // spm.detach();
    air = air_pin; //エアピン
    servo_p = spp_pin;
    servo_m = spm_pin;
    // deg_1 = deg1; //供給時の角度
    // deg_2 = deg2; //普段の角度
    t_1 = t1; //供給時間
    t_2 = t2; //リロード時間
    t_c = tc; //上下時間
}
void hanging_system::air_change()
{
    digitalWrite(air, !now_air_pos); //エアを今と反対の出力にする
    air_change_time = millis();      //エアの動作開始時間を記録
    air_is_moving = true;            //エア動作中に状態変更
}
void hanging_system::hang(boolean hang_pos, unsigned int deg1, unsigned int deg2) //指定したほうに供給(deg2=初期位置)
{
    if (!air_is_moving) //エアが動作中でないときのみリクエスト受けつけ
    {
        deg_1 = deg1;                 //供給角度
        deg_2 = deg2;                 //停止角度
        has_requested_hanging = true; //供給リクエスト
        if (now_air_pos != hang_pos)  //今供給不可能位置なら
            air_change();             //エアを逆にして，
    }
}
void hanging_system::empty_hang(boolean hang_pos) //かけずに指定されたほうを上げる
{
    if (!air_is_moving)              //エアが動作中でないときのみリクエスト受けつけ
        if (now_air_pos == hang_pos) //逆位置なら
            air_change();            //エアを逆にする
}
void hanging_system::always_run_function() //常時動作して状態更新関数
{
    if (air_is_moving && (millis() - air_change_time) > t_c) //エアが動いてて一定時間たったら
    {
        now_air_pos = !now_air_pos; //エア位置を逆に
        air_is_moving = false;      //エア動いてないよにする
    }
    if (!air_is_moving && has_requested_hanging) //エアが動き終わり，供給要求があったとき
    {
        has_requested_hanging = false; //供給要求をリセット
        servo_move(deg_1);             //サーボを供給位置に
        is_supplying = true;           //供給中に状態変更
        supply_start_time = millis();  //供給開始時間を更新
    }
    if (is_supplying && (millis() - supply_start_time) > t_1) //サーボが動き始めてt1たったら
    {
        is_supplying = false; //供給中じゃなくする
        air_change();         //エアを再び上げる
        servo_move(deg_2);    //サーボを元に戻す
    }
    if ((millis() - supply_start_time) > (t_1 + t_2)) //サーボ動作停止for省電力
    {
        spp.detach(); //サーボOFF
        spm.detach(); //サーボOFF
    }
}
void hanging_system::servo_move(int deg) //サーボ動作関数
{
    if (now_air_pos == 0) //今下なら
    {
        spm.attach(servo_m); //サーボ稼働
        spm.write(deg);      //下の供給地点に供給
    }
    else if (now_air_pos == 1) //今上なら
    {
        spp.attach(servo_p); //サーボ稼働
        spp.write(deg);      //上の供給地点に供給
    }
}

void hanging_system::show_all_state()
{
    Serial.print("sst:");
    Serial.print(supply_start_time);
    Serial.print(",act:");
    Serial.print(air_change_time);
    Serial.print(",is:");
    Serial.print(is_supplying);
    Serial.print(",nap:");
    Serial.print(now_air_pos);
    Serial.print(",aim");
    Serial.print(air_is_moving);
    Serial.print(",hrh");
    Serial.println(has_requested_hanging);
}
