#include <M5StickC.h>

double Ttime = 637.5; // Normal: 562usec, My Toshiba Ceiling Light is 637.5usec.

int cursor = 0;

struct REMOTE {
  char name[9];
  int bitnum;
  uint64_t command;
};
// リモコンコード一覧
REMOTE remote[] = {
  { "ON" , 32, 0xE730E817UL },
  { "M2" , 64, 0xE73017E8B0705017UL },
  { "OFF" , 32, 0xE730D02FUL },
  
};

void setup() {
  ledcSetup(0,38000,8);   //38kHz
  ledcAttachPin(9, 0);    //IR:9, testgpio-output:26
  
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextFont(7);
  M5.Lcd.setCursor(0, 8);
  M5.Lcd.print("0");
}

void loop() {
  
  M5.update();

  if ( M5.BtnA.wasPressed() ) {
    doLeaderPulse();

    for (int a=remote[cursor].bitnum-1; a>=0; a--) {
      doPulse((remote[cursor].command >> a) & 0x0000000000000001);
    }
    
    doEndPulse();

    M5.Lcd.setCursor(0, 8);
    M5.Lcd.print(String(cursor));
    cursor++;
    if (cursor >= 3) {
      cursor = 0;
    }
  }
  
  delay(100);
}

void doLeaderPulse() {
  ledcWrite(0,256/3);
  delayMicroseconds(Ttime * 16);
  ledcWrite(0,0);
  delayMicroseconds(Ttime * 8);
}

void doEndPulse() {
  ledcWrite(0,256/3);
  delayMicroseconds(Ttime);
  ledcWrite(0,0);
  delayMicroseconds(Ttime);
}


void doPulse(int num) {
  ledcWrite(0,256/3);
  delayMicroseconds(Ttime);
  ledcWrite(0,0);

  if (num == 1) {
    delayMicroseconds(Ttime * 3);
  } else {
    delayMicroseconds(Ttime);
  }
}
