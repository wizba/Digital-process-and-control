
#include <TimerOne.h>
#include <NewPing.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 500

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int blue=7;
int green=6;
int red=5;

char message=' ';
void setup() 
{
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  Serial.begin(9600);   
 Timer1.initialize(1000000/2);
 Timer1.attachInterrupt(allowBlink);
}

int redLedState=0;
volatile int blinkValue=0;


void loop()
{
  unsigned int distance = sonar.ping_cm();
  checkObject(distance);
  Serial.write(distance);
      delay(50); 
}

void setRGB_LED(int rValue,int gValue,int bValue)
{
  analogWrite(red,rValue);
  analogWrite(green,gValue);
  analogWrite(blue,bValue);
}

void checkObject(unsigned int distance )
{
   if( distance <=20)
   {
     noInterrupts();
     redLedState=blinkValue;
     interrupts();
     
   message='A';
    
     setRGB_LED(redLedState,0,0);
   }
   else
   {
    setRGB_LED(0,255,0);
    message='A';
   }
   
 
}

void allowBlink()
{
  (blinkValue == 255)?blinkValue=0:blinkValue=255;
}
