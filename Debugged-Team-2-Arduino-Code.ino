#include <SPI.h>
#include <Pixy2.h>
#include "Ultrasonic.h"
#include <Servo.h>

Servo myservo;


// Code for main pixy object
Pixy2 pixy;

const int trigPin = 5;
const int echoPin = 6;
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

  pixy.init();
}

void loop () {
  digitalWrite (trigPin, LOW);
  delayMicroseconds (2);
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);
  duration = pulseIn (echoPin, HIGH);
  cm = (duration / 2) / 29.1;
  Serial.println (cm);

  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];

  blocks = pixy.ccc.getBlocks();

  myservo.write(90);
    if (pixy.ccc.numBlocks)
    {
      for (i=0;i< pixy.ccc.numBlocks;i++)
      {
        if (pixy.ccc.blocks[i].m_signature == sigRed && 20 <= cm  && cm <= 50 ) // defined sigRed=1 and sigBlue=2
        {
          myservo.write(180);
          Serial.println ("Red");
          delay (10);
        }
        else if (pixy.ccc.blocks[i].m_signature == sigBlue && 20 <= cm && cm <= 50)
        {
          myservo.write(180);
          Serial.println ("Blue");
          delay (10);
        }
        else 
         {
          myservo.write(90);
          Serial.println ("Error");
          delay (10);
        }
        }
            
      }
      pixy.ccc.blocks[i].print();
    }
