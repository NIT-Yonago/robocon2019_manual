//Morita Daiki 2019 @NIT.yonago
//マイコン:arduino pro mini 互換（自作）
//👆See KiCad/wii_controller

#include <WiiChuck.h> //Wiiのライブラリを使う

Accessory Wii; //つないだアクセサリーの名前をWiiとする

boolean sta13 = 0; //LED状態

void setup() //設定
{
  Serial.begin(115200);    //シリアルボートレート
  pinMode(13, OUTPUT);     //13番ピンを出力に
  Wii.begin();             //コントローラ接続
  if (Wii.type == Unknown) //Wiiの種類が分からないとき
    Wii.type = WIICLASSIC; //クラシックコントローラーだよ
}
void loop()
{
  digitalWrite(13, sta13); //LED更新
  sta13 = !sta13;          //LED状態切り替え

  uint8_t wii_data[WII_VALUES_ARRAY_SIZE]; //長さWII_VALUES_ARRAY_SIZE(=19)のwii_dataという配列を用意

  Wii.readData(); //Wiiデータ取得

  //配列の各要素に値を代入
  wii_data[0] = Wii.getButtonA();           //0,1
  wii_data[1] = Wii.getButtonX();           //0,1
  wii_data[2] = Wii.getButtonY();           //0,1
  wii_data[3] = Wii.getButtonB();           //0,1
  wii_data[4] = Wii.getPlusButton();        //0,1
  wii_data[5] = Wii.getButtonHome();        //0,1
  wii_data[6] = Wii.getButtonMinus();       //0,1
  wii_data[7] = Wii.getPadRight();          //0,1
  wii_data[8] = Wii.getPadUp();             //0,1
  wii_data[9] = Wii.getPadLeft();           //0,1
  wii_data[10] = Wii.getPadDown();          //0,1
  wii_data[11] = Wii.getTriggerLeft();      //0,1
  wii_data[12] = Wii.getButtonZLeft() > 0;  //0,16(0,32?)みたいなデータを1,0に変換
  wii_data[13] = Wii.getTriggerRight();     //0,1
  wii_data[14] = Wii.getButtonZRight() > 0; //0,16(0,32?)みたいなデータを1,0に変換
  wii_data[15] = Wii.getJoyXLeft();         //0~63
  wii_data[16] = Wii.getJoyYLeft();         //0~63
  wii_data[17] = Wii.getJoyXRight();        //0~31
  wii_data[18] = Wii.getJoyYRight();        //0~31

  Serial.write(0xff);         //ヘッダ＝11111111
  Serial.write(wii_data, 19); //19個のデータ送信
  delay(50);                  //20ms待つ
}
