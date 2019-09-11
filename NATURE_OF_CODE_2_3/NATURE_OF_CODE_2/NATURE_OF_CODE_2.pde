acc demo=new acc();
PFont f;
void setup()
{
  size(640,346);
   f=createFont("Bauhaus93-48",48);
}
void draw()
{
 
PVector gravity=new PVector (0,0.03);
demo.force(gravity);
if(mousePressed){
  PVector wind=new PVector (0.1,0);
demo.force(wind);
}

demo.update();
demo.checkEdges();
demo.elps(f);

}