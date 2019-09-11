class Timer
{
  protected :   
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

class RgbLed
{
  private:
      int redPin;
      int greenPin;
      int bluePin;
      String type;
      int selectState;
      float red,green,blue;
  public:
      RgbLed(int r,int g,int b,String t)
      :redPin(r),greenPin(g),bluePin(b),type(t)
      {
        pinMode(redPin,OUTPUT);
        pinMode(greenPin,OUTPUT);
        pinMode(bluePin,OUTPUT);
        red=0;
        green=0;
        blue=0;
        
        selectState=1;
      }
      void automateChange(long timerMax)
      {
            
             //to be completed 
               //ease in 
                 if(selectState== 1) 
                  {
                    if(red < 255)
                    {
                      green=0;
                      blue=0;
                      red+=25.5;
                    }else
                    if(red >=255 && green < 255)
                    {
                      green+=25.5;
                      blue=0;
                      red=255;
                    }else
                    {
                      selectState=2;
                    }
                  } else 
                  //change to green 
                  if(selectState==2)
                  {
                     green=255;
                    blue=0;
                    red=0;
                    selectState=3;
                  }else 
                  //change to blue
                  if(selectState==3)
                  {
                   green=0;
                    blue=255;
                    red=0;
                   selectState=1;
                  }                                  
          changeColor();     
      }
      void recieveValues(char color)
      {
          if(  toupper(color)=='R')
          {
             red=255;
             blue=0;
             green=0;
          }else if( toupper(color)=='G' )
                  {
                    red=0;
                    blue=0;
                    green=255;
                  }
                    else if(toupper(color)=='B')
                          {
                              
                            red=0;
                            blue=255;
                            green=0;
                          }
              changeColor();
      }
     void changeColor()
      {
        analogWrite(redPin,red);
        analogWrite(greenPin,green);
        analogWrite(bluePin,blue);  
      }
};
RgbLed *rgb;
Timer *T;
void setup()
{
  T=new Timer();
 rgb=new RgbLed(6,9,10,"CA");
 
 Serial.begin(9600);
}

void loop()
{
 char color;

   /* if(Serial.available())
   {
       color =Serial.read();
       rgb->recieveValues(color);
       Serial.println("printed");
   } */
   if(T->delay_func(1,'S'))
 rgb->automateChange(1);
}


