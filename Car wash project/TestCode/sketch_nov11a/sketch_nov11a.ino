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
long intervalGate1=3000;
boolean gotoOPenGate1;
boolean gotoCloseGate1;
boolean stopGate=false;
boolean listenForCar=false;
//timer variable
long currentTime=0;

void setup()
{
   pinMode(irSensorPin,INPUT);
  pinMode(carPresenceButton,INPUT);
  Serial.begin(9600);
}

void loop()
{
  while(gotoCheckCarAtGate)
  {
   boolean notDetected=digitalRead(irSensorPin);
    if( !notDetected )
    {
        Serial.println("Car at the gate ");
        gotoCheckCarAtGate=false;
        gotoCheckNumOFCars=true;
    }
    
  }
  while(gotoCheckNumOFCars)
  {
    if(  carsWashed < 10)
    {
       
        gotoCheckCarPresence=true;
        Serial.println("Go to check space ");
       
    }else
    {
      Serial.println("NO");
      gotoCheckCarAtGate=true;
      gotoCheckCarPresence=false;
    }
    gotoCheckNumOFCars=false;
  }
  
  while(gotoCheckCarPresence)
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
  
  while(waitForGate1)
  {
      currentTime=millis();
    if(currentTime-prevGate1 >= intervalGate1)
    {
      prevGate1=currentTime;
      //go to open gate
      Serial.println("gate opened");
      listenForCar=true;  
       waitForGate1=false;
       stopGate=true;
      prevGa1=currentTime;
    }
    if(stopGate ==false)
    {
     Serial.println("opening a gate");
    }
  }
  
  while(listenForCar)
  {
      if(digitalRead(carPresenceButton))
      {
        Serial.println("car entered");
        listenForCar=false;
        gotoCloseGate1=true;
        
      }  
  }
  
  while(gotoCloseGate1)
  {
    if(currentTime-prevGa1 == 5000)
    {
      prevGa1=currentTime;
      //go to open gate
      Serial.println("close gate 1");
      
    }
  }
}
