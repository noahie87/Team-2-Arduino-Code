#include <SPI.h>
#include <Pixy2.h>
#include "Ultrasonic.h"

Servo myservo;
Ultrasonic (12, 13);

// Code for main pixy object
Pixy pixy;

const int trigPin = 9;
const int echoPin = 10;
long duration, cm;


int sigRed = 1; 
int sigBlue = 2;

void setup () {
  myservo.attach (3);
  Serial.begin(9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.print("Starting...\n");
  int sigRed = 1; 
  int sigBlue = 2;

  pixy in.it();
}

int sigRed = 1; 
int sigBlue = 2;

void loop () {
  digitalWrite (trigPin, LOW)
  delayMicroseconds (2);
  digitalWrite (trigPin, HIGH)
  delayMicroseconds (10);
  digitalWrite (trigPin LOW)
  duration = pulseIn (echoPin, HIGH)
  cm = (duration / 2) / 29.1
  serial.println (cm)

  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];

  blocks = pixy.getBlocks()

    if (pixy.numBlocks);
    {
      for (i=0,i< pixy.numBlocks;i++)
      {
        if (pixy.blocks[i].signature == sigRed && cm <== ) // defined sigRed=1 and sigBlue=2
        {
          myservo.write(90);
          delay (10);
        }
        else if (pixy.blocks[i].signature == sigBlue)
        {
          myservo.write(90);
          delay (10);
        }
        
      }
    }



}
