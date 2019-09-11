acc demo=new acc();
PFont f;
void setup()
{
  size(400,400);
   f=createFont("Bauhaus93-48",48);
}
void draw()
{

demo.update();
demo.checkEdges();
demo.elps(f);
}