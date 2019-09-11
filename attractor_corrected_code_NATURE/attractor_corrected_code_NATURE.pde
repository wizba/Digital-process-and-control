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
  }
}