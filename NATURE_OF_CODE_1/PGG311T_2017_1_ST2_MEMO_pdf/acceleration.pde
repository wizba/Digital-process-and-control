class acc
{
  private PVector loc;
  private PVector velocity;
  private PVector acceleration;
  public PFont f;  
  public acc()
  {
    loc=new PVector(width/2,height/2);
    velocity=new PVector(0,0);
    acceleration=new PVector(0.01,0);
    
   
  }
void update()
{
  PVector mouseV=new PVector(mouseX,mouseY);
  mouseV.sub(loc);
  mouseV.setMag(0.1);
  acceleration=mouseV;
  
  
 // acceleration=PVector.random2D();
  velocity.add(acceleration);
  loc.add(velocity);
  velocity.limit(5);
}

void checkEdges()
{
  if(loc.x>width) loc.x=0;
  if(loc.y>height)loc.y=0;
  if(loc.x<0) loc.x=width;
  if(loc.y<0) loc.y=height;
}

void elps(PFont pf)
{
  background(0);
  f=pf;
 ellipse(loc.x,loc.y,50,50);
 
 textFont(f);

 text(str(velocity.x),100,200);
}
}