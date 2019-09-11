boolean waitForGate1;
long prevGate1=0;
long intervalGate1=3000;
boolean gotoOPenGate1;
boolean stopGate=false;
long currentTime=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
currentTime=millis();
 if(currentTime-prevGate1 >= intervalGate1 && currentTime-prevGate1 < 4000)
    {
      prevGate1=currentTime;
      //go to open gate
      
      Serial.println(prevGate1);
       waitForGate1=false;
       stopGate=true;
      
    }
    
    if(stopGate ==false)
    {
     Serial.println("opening gate"); 
    }
    
    
}
