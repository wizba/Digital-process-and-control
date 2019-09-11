int irSensorReading=3;
int carPresence=2;
boolean startProcess;


int max_car_washed=10;
int countCars=0;

boolean carAvalable=false;
boolean waitOrDone=true;
boolean goToDisplay=false;
boolean gotoDetectCar=true;
boolean gotoNumOfCar=false;
void setup()
{
 Serial.begin(9600);
 pinMode( irSensorReading,INPUT);
 pinMode( carPresence ,INPUT); 
}

void loop()
{
  if(gotoDetectCar==true)
      carDetected();
 
  if(gotoNumOfCar == true)
  {
      
      if( washedCars()<10 )
      { 
        Serial.println("cars washed are less than 10");
        waitOrDone=false;
        //go to check if there is car in the wash
      }else
      if( washedCars()==10)
      {
        //wait for refill
        waitOrDone=true;
      }
      gotoNumOfCar=false;
  }
  if( !waitOrDone)
  {
    //check car presence
     carAvailabel();
     waitOrDone=true; 
  }
  
}

void carDetected()
{
  boolean Notdetect;
  
  Notdetect=digitalRead(irSensorReading);

  if(!Notdetect)
  {
    Serial.println("car detected at the gate");
    gotoNumOfCar=true;
  }else
  {
     gotoNumOfCar=false;
  }

}


int  washedCars()
{
  return countCars; 
}
void carAvailabel()
{
  boolean readCar=digitalRead(carPresence);//gonna read from dip switch

  if( readCar == HIGH )
  {
    
    Serial.println("NO");
    
    //back to carDetected
    gotoDetectCar=true;
  }
  else
  if( readCar== LOW)
  {
    Serial.println("yes");
    //Go to open gate
    //increment car number
  }

  
}
