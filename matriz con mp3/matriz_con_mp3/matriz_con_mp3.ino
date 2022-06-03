#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <SPI.h>
#include <DMD2.h>
#include <fonts/Droid_Sans_12.h>
#include <fonts/Droid_Sans_16.h>

#include <fonts/Arial14.h>
#include <fonts/SystemFont5x7.h>

//Pulsadores
const int s1 = 22; // pulsadores
const int s2 = 24;
const int s3 = 26;


const int led = 5; // led

int state1 = 0; // estados para las entradas digitales
int last1 = 1;
int state2 = 0;

int last2 = 1;

int state3 = 0;
int last3 = 1;

SoftwareSerial mySoftwareSerial(10, 12); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

int n=0;
SoftDMD dmd(2,1); // DMD controls the entire display
DMD_TextBox box(dmd,2,1); 



void setup()
{
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

  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);

  pinMode(led, OUTPUT);
  dmd.setBrightness(10);
  dmd.selectFont(Droid_Sans_16);
  dmd.begin();
     
     
     digitalWrite(led, 1);
     delay(1000);
     digitalWrite(led, 0);

}

void loop()
{


  state1 = digitalRead(s1);
  state2 = digitalRead(s2);
  state3 = digitalRead(s3);

  if (state1 != last1) {
    
    if (state1 == HIGH) {
      myDFPlayer.play(1);
      Serial.print(state1);
      digitalWrite(led, 1);
      delay(1000);
     digitalWrite(led, 0);
   
///////////////////
dmd.clearScreen();
    const char *next = "INGRESA LA BOTELLA
    ";
    while(*next) {
   // Serial.print(*next);
    box.print(*next);
    delay(200);
    next++;
  }
    delay(600);
  dmd.fillScreen(true);
  delay(500);
  dmd.clearScreen();
  delay(500);
  box.clear();


    
    }
  }
  
  last1  = state1;


 ////////////////////////
  if (state2 != last2 ) {
    if (state2 == HIGH) {
      myDFPlayer.play(2);
      digitalWrite(led, 1);
      delay(1000);
      digitalWrite(led, 0);
   
      
    dmd.clearScreen();
    const char *next ="LEYENDO BOTELLA";
    while(*next) {
    Serial.print(*next);
    box.print(*next);
    delay(200);
    next++;
  }
    delay(600);
    dmd.fillScreen(true);
    delay(500);
    dmd.clearScreen();
    delay(500);
    box.clear();

      
    }
  }
  last2  = state2;


 ////////////////////////
  if (state3 != last3 ) {
    if (state3 == HIGH) {
      myDFPlayer.play(3);
      digitalWrite(led, 1);
      delay(1000);
      digitalWrite(led, 0);
   
      
    dmd.clearScreen();
    const char *next ="RETIRE SU DINERO ";
    while(*next) {
    Serial.print(*next);
    box.print(*next);
    delay(200);
    next++;
  }
    delay(600);
    dmd.fillScreen(true);
    delay(500);
    dmd.clearScreen();
    delay(500);
    box.clear();

      
    }
  }
  last3  = state3;


}
