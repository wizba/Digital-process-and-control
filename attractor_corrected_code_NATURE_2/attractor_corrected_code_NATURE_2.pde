c call[]=new c[50];
attractor At;
void setup()
{
  size(630,400);
  for(int i=0;i<call.length;i++)
  {
    call[i]=new c();
  }
  
}
void draw()
{
  background(255);
  attractor At=new attractor();
  for(c m:call)
  {
    At.attractorDisp();
    m.forceRecive( At);
    m.update();
    m.object();
    
    float aSpeed=0;
    if(keyCode==UP)
      {
        
        aSpeed+=0.5;
      }else if(keyCode==DOWN)
              {
                if(aSpeed>0)
                aSpeed-=0.5;
              }
       m.inRotation(aSpeed );
  }
  
  
}