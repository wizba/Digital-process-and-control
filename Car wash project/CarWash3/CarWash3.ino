
class Timer
{
  private :   
     long previous;
     long currentTime;
     
  public:
    
    Timer()
    {
      
      previous=0;
      currentTime=0;      
    }
    
  boolean delay_func(int maxT,char timerType)
  {
    if(timerType=='S')
      maxT=maxT*1000;
      currentTime=millis();
    if(currentTime-previous>=maxT)
    {
        previous=currentTime;
        return true;
    }
    else{
        return false;
    }
  }  
  
};

/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
int irSensorPin=7;
int data= 192;
boolean sensorState;


const int latchPin = 12;//Pin connected to latchPin of 74HC595//green
const int clockPin = 8;//Pin connected to clockPin of 74HC595 //yellow
const int dataPin = 11; //Pin connected to dataPin of 74HC595 //blue

////////////////////: Number of project :///////////////////////
int maxNumOfCars=10;
int carEnteringCount=0;
//////////////////////////////////////////////////////////////
///////////////////:is there car available://////////////////
boolean isThereCarIn=false;
int checkCarInput=4;

///////////////////: go to timing ://///////////////////////
boolean waitForFiveSec=0;
boolean openGate=1;
///////////////////////////////////////////////////////////
Timer *timer1;//declare an object fo the timer class 

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  timer1=new Timer();//create an object for the timer class 

  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(checkCarInput,INPUT);
  pinMode(irSensorPin,INPUT);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  sensorState=digitalRead(irSensorPin);
  
  if(!sensorState)
  {
    //check number of cars
    
    if(carEnteringCount < maxNumOfCars)
    {
        //check if there is a car in 
      isThereCarIn=digitalRead(checkCarInput);

      if(isThereCarIn)
      {
          data=200;//display N
      }
       else   
       {
         data=130;//display G

          //go to wait for 3 seconds for the gate to open 
         openGate=true;
         waitForFiveSec=true;
       }  
    } 
    else
    {
      data=200;//display N
    }

  }

  if( timer1->delay_func(3,'S') && waitForFiveSec )
  {
    Serial.println("done opening");
    openGate=false;
    waitForFiveSec=false;
  }
  else
  if(  waitForFiveSec && openGate )
  {
    Serial.println("opening gate");
  }

//display
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,data);
    digitalWrite(latchPin,HIGH); 
}
