c call[]=new c[3];

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
  for(c m:call)
  {
    m.calc();
    m.object();
  }
}