#include <SPI.h>
#include <DMD2.h>
#include <fonts/Droid_Sans_12.h>
#include <fonts/Droid_Sans_16.h>
#include <fonts/Arial14.h>
#include <fonts/SystemFont5x7.h>

//   librerias para voz

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


const int buttonPlus   = 2;  
const int buttonMinus  = 3;
const int buttonReset  = 4;
int buttonState1= 0;
int buttonState2= 0;
int buttonState3= 0;
int n=0;
SoftDMD dmd(2,1); // DMD controls the entire display
DMD_TextBox box(dmd,2,1);  


// para l voz

const int led = 13; // led

int state1 = 0; // estados para las entradas digitales
int last1 = 1;
int state2 = 0;
int last2 = 1;

SoftwareSerial mySoftwareSerial(10, 12); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

////



void setup() {
  pinMode(buttonPlus, INPUT);
  pinMode(buttonMinus, INPUT);
  pinMode(buttonReset, INPUT);
  dmd.setBrightness(10);
  dmd.selectFont(Droid_Sans_16);
  dmd.begin();

 mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(10);  //Set volume value (0~30).
  myDFPlayer.volumeUp(); //Volume Up
  myDFPlayer.volumeDown(); //Volume Down

  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  //----Set device we use SD as default----
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

  pinMode(led, OUTPUT);
  
}

void loop() {
  
  //int x=15;
  //dmd.selectFont(Droid_Sans_16);
  buttonState1 = digitalRead(buttonPlus);
  buttonState2 = digitalRead(buttonMinus);
  buttonState3 = digitalRead(buttonReset);

digitalWrite(led, 0);

    if (buttonState1 == LOW) {
      myDFPlayer.play(1);
      Serial.print(buttonState1);
      digitalWrite(led, 1);
      delay(1000);
   
  }
    

}
