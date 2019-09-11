int lacthPin=9;
int clockPin=12;
int dataPin=11;
byte data=0b0000000;

void setup()
{
  pinMode(lacthPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop()
{
  clockRegister(lacthPin,clockPin);
}

void clockRegister(int l_pin,int c_pin)
{
  digitalWrite(l_pin,LOW);
  digitalWrite(c_pin,LOW);
 
  delay(250);
 digitalWrite(c_pin,HIGH);
  digitalWrite(l_pin,HIGH);
  
  delay(250);
  
  
  
  digitalWrite(l_pin,LOW);
  digitalWrite(c_pin,LOW);
  
  delay(250);
 digitalWrite(c_pin,HIGH);
  digitalWrite(l_pin,HIGH);
  
  delay(250);
  
  
}
