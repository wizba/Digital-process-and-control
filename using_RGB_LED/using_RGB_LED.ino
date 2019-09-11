
int pot = A0;
//int glowLed=10;
int ledState;
int Red=6;
int Green=9;
int Blue=10;
void setup()
{
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
}

void loop()
{
  /*ledState=analogRead(pot);
  ledState=map(ledState,0,1023,0,255);
  
  analogWrite(glowLed,ledState);
  */
  ledState=analogRead(pot);
  if(ledState<=341)
  {
    ledState=map(ledState,0,1023,0,255);
    setColor(ledState, 0, 0);
  }else
  if(ledState > 341 && ledState<=682)
  {
    ledState=map(ledState,0,1023,0,255);
    setColor(0, ledState, 0);
  }
  else
  if(ledState > 682 && ledState<=1023)
  {
    ledState=map(ledState,0,1023,0,255);
    setColor(0, 0,ledState );
  }
  
}
void setColor(int blue, int green, int red)
{
  
  analogWrite(Red, blue);
  analogWrite(Green, green);
  analogWrite(Blue, red);  
}
