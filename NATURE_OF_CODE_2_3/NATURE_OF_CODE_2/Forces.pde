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
    acceleration=new PVector(0,0);
  }
void force(PVector Force)
{
  acceleration.add(Force);//a=f/m
}
void update()
{ 
  
 // acceleration=PVector.random2D();
  velocity.add(acceleration);//a=(vf-vi)/t
  loc.add(velocity);//
 // velocity.limit(5);
 //velocity.setMag(5);
 acceleration.mult(0);
}

void checkEdges()
{
  if(loc.x>width)
    {
      loc.x=width;
      velocity.x*=-1;
      
    }else if(loc.x<0)
        {
          loc.x=0;
          velocity.x*=-1; 
        }
        
    if(loc.y>height)
    {
      loc.y=height;
      velocity.y*=-1;
      
    }else if(loc.y<0)
        {
          loc.y=0;
          velocity.y*=-1; 
        }
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