#include <SPI.h>
#include <DMD2.h>
#include <fonts/Droid_Sans_12.h>
#include <fonts/Droid_Sans_16.h>
const int buttonPlus   = 2;  
const int buttonMinus  = 3;
const int buttonReset  = 4;
int buttonState1= 0;
int buttonState2= 0;
int buttonState3= 0;
int n=0;
SoftDMD dmd(1,1); // DMD controls the entire display
DMD_TextBox box(dmd,1,3);  
const char *INTRO = "ELECTROMARK";
void setup() {
  pinMode(buttonPlus, INPUT);
  pinMode(buttonMinus, INPUT);
  pinMode(buttonReset, INPUT);
  dmd.setBrightness(10);
  dmd.selectFont(Droid_Sans_12);
  dmd.begin();
  display_intro();
}

void loop() {
  int x=13;
  dmd.selectFont(Droid_Sans_16);
  buttonState1 = digitalRead(buttonPlus);
  buttonState2 = digitalRead(buttonMinus);
  buttonState3 = digitalRead(buttonReset);
  if (buttonState1 == HIGH) {
    dmd.clearScreen();
    n = n + 1;  
    if (n >99){n=0;}
    delay(500);
  }
  if (buttonState2 == HIGH) {
    dmd.clearScreen();
    n = n - 1;
    if (n <0){n=99;}
    delay(500);
  }
  if (buttonState3 == HIGH) {
    dmd.clearScreen();
    n = 0;
    delay(500);
  }
  if (n >9){x=10;}
  if (n >19){x=8;}
  dmd.drawString(x,1,String(n));
}

void display_intro(){
  const char *next = INTRO;
  while(*next) {
    Serial.print(*next);
    box.print(*next);
    delay(300);
    next++;
  }
  delay(600);
  dmd.fillScreen(true);
  delay(500);
  dmd.clearScreen();
  delay(500);
  box.clear();
}
