int irSensorPin=3;
int carPresenceButton=2;


boolean gotoCheckCarAtGate=true;
boolean gotoCheckNumOFCars;
boolean gotoCheckCarPresence;

//got to check no of cars
int carsWashed=0;
 boolean carIn;
// gate one variables
boolean waitForGate1;
long prevGate1=0;
long prevGa1=0;
long intervalGate1=10000;
boolean gotoOPenGate1;
boolean stopGate=false;
boolean CarHasEntered=false;
//timer variable
long currentTime=0;
void setup() 
{
  // put your setup code here, to run once:

  pinMode(irSensorPin,INPUT);
  pinMode(carPresenceButton,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  // put your main code here, to run repeatedly:

  boolean notDetected;

  if(gotoCheckCarAtGate)
  { 
    notDetected=digitalRead(irSensorPin);
  
    if( !notDetected )
    {
        Serial.println("Car at the gate ");
        gotoCheckCarAtGate=false;
        gotoCheckNumOFCars=true;
    }
        
  }

  if(gotoCheckNumOFCars)
  {
    if(  carsWashed < 10)
    {
       
        gotoCheckCarPresence=true;
       
    }else
    {
      Serial.println("NO");
      
      gotoCheckCarAtGate=true;
      gotoCheckCarPresence=false;
    }
    gotoCheckNumOFCars=false;
   
  }

  if( gotoCheckCarPresence )
  {
      boolean carInWash;
      carInWash=digitalRead(carPresenceButton);

      if(carInWash)
      {
        Serial.println("NO");
        
        gotoCheckCarAtGate=true;
      }
      else
      {
        Serial.println("GO");
        waitForGate1=true;
        Serial.println("Waiting for gate 1");
      }
      gotoCheckCarPresence=false;
  }

  if(waitForGate1)
  {
   
      currentTime=millis();
    if(currentTime-prevGate1 >= intervalGate1)
    {
      prevGate1=currentTime;
      //go to open gate
      Serial.println("opening gate");
      CarHasEntered=true;  
       waitForGate1=false;
       stopGate=true;
      prevGa1=currentTime;
    }
    if(stopGate ==false)
    {
     Serial.println("opening gate");
     
     //go to check if car has entered
     
    }
        
    
   }

  if(CarHasEntered)
   {
    
     Serial.println("has enetred");
     carIn=digitalRead(carPresenceButton);
     if(carIn)
     {
       CarHasEntered=false;
     }

   }
   
  
     if(carIn== true && CarHasEntered == false )
     {
              
              delay(5000);
              Serial.println("done");
              carIn=false;
           gotoCheckCarAtGate=true;
     }
   
}
