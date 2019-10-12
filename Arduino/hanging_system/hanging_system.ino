#include <Servo.h>          //サーボ使うよ
#include "hanging_system.h" //かける機構ライブラリ
#include <SoftwareSerial.h> //MDグリーンへの送信用ソフトウェアシリアル

//初期位置，供給位置
const int degpA[2] = {90, 170}; //サーボA-plus
const int degmA[2] = {90, 170}; //サーボA-minus
const int degpB[2] = {90, 170}; //サーボA-plus
const int degmB[2] = {90, 170}; //サーボA-minus

//上の時の供給，下の時の供給,エアー，上の供給角度
//spp,spm,air,degpdef,degmdef,t1,t2,tc
hanging_system unit_A(2, 3, 11, degpA[0], degmA[0], 500, 300, 1000);
hanging_system unit_B(4, 5, 12, degpB[0], degmB[0], 500, 300, 1000);

// SoftwareSerial mdblack(A1, A0); //rx,txモタドらへの送信

uint8_t mdblack_datas[4]; //モタドらへの送信データ

boolean now_button_state[15];  //現在ボタン
boolean last_button_state[15]; //1個前ボタン
boolean button_rize[15];       //ボタンが立ち上がったか
int sta13 = 0;                 //LEDちかちか用
void setup()
{
   pinMode(8, OUTPUT);    //起動確認LED
   pinMode(13, OUTPUT);   //シリアル確認LED
   digitalWrite(8, HIGH); //起動確認LED
   digitalWrite(13, LOW); //シリアル確認LED
   Serial.begin(115200);  //XBee通信速度
   // mdblack.begin(9600);   //モタドら通信速度
}

void loop()
{
   if (Serial.available() > 0) //シリアルが受信可能時
   {
      if (Serial.read() == 0xff) //ヘッダーデータ来てたら
      {
         digitalWrite(13, sta13); //シリアル状態LED更新
         sta13 = !sta13;          //シリアル状態更新

         uint8_t values[19];           //受信データ格納配列
         Serial.readBytes(values, 19); //データ読みこみ

         //ボタン現状態と立ち上がり検知
         for (int i = 0; i < 15; i++) //0~14はWiiのボタンデータ
         {
            now_button_state[i] = (values[i] > 0);                         //現在ボタン更新(>0なのは，ZやLボタンが0~16みたいな値を持つから)
            button_rize[i] = !last_button_state[i] && now_button_state[i]; //前０で今１だと立ち上がり
            last_button_state[i] = now_button_state[i];                    //今を過去に
         }

         mdblack_datas[0] = values[15];                   //LX
         mdblack_datas[1] = values[16];                   //LY
         mdblack_datas[2] = values[17];                   //XR
         mdblack_datas[3] = (button_rize[0] << 0) |       //開閉
                            (now_button_state[7] << 1) |  //出っ張る
                            (now_button_state[9] << 2) |  //縮む
                            (now_button_state[8] << 3) |  //↑
                            (now_button_state[10] << 4) | //↓
                            ((now_button_state[1] &&      //X&
                              now_button_state[5])        //HOME
                             << 5) |                      //
                            (now_button_state[2]) << 6;   //Y

         // mdblack.listen();    //ソフトウェアシリアルを使えるように
         // mdblack.write(0xff); //ヘッダ送信
         // mdblack.write(mdblack_datas, 4);
         Serial.write(0xff);
         Serial.write(mdblack_datas, 4);
         // send_bytes(mdblack, send_datas, 5); //モーターとエアのデータ送信

         if (!now_button_state[6]) //⊖ボタン押してない（普通に供給してかっけるとき）
         {
            //右
            if (button_rize[14])                   //ZR
               unit_A.hang(0, degmA[1], degmA[0]); //奥　にかけて上がる
            else if (button_rize[13])              //R
               unit_A.hang(1, degpA[1], degpA[0]); //手前にかけて上がる
            //左
            if (button_rize[12])                   //ZL
               unit_B.hang(0, degmB[1], degmB[0]); //奥　にかけて上がる
            else if (button_rize[11])              //L
               unit_B.hang(1, degpB[1], degpB[0]); //手前にかけて上がる
         }
         else //⊖ボタン押してるとき（ただ指定したほうを上げるだけ）
         {
            //右
            if (button_rize[14])      //ZR
               unit_A.empty_hang(0);  //奥　が上がる
            else if (button_rize[13]) //R
               unit_A.empty_hang(1);  //手前が上がる
            //左
            if (button_rize[12])      //ZL
               unit_B.empty_hang(0);  //奥　が上がる
            else if (button_rize[11]) //L
               unit_B.empty_hang(1);  //手前が上がる
         }
      }
   }
   unit_A.always_run_function(); //ハンギングシステムの常時更新
   unit_B.always_run_function(); //ハンギングシステムの常時更新
}