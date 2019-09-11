class attracted
{
  private PVector v;
  public PVector loc;
  private PVector a;
  private color c;
  public float mass;
  PVector dir;
  
  public attracted()
  {
    v=new PVector(0,0);
    loc=new PVector(random(6,590),random(6,590));
    a=new PVector(0,0);
    mass =random(1,3.5);
    dir=new PVector(0,0);
    c=color(random(0,255),random(0,255),random(0,255));
  }
  
  
  void calcs()
  {
   
    dir.setMag(0.05);
    a=dir;
      v.add(a);
      
      
      loc.add(v);
      a.mult(0);
  }
  
  void forceAccumulator(PVector force)
  {
    
      dir=force;
     
  }
 
  void showShape()
 {
   stroke(c);
   
   strokeWeight(2);
     ellipse(loc.x,loc.y,0.5,0.5);
 }
 
  void edges()
  {
    if(loc.x<0)
    {
    
      v.x*=-1;
    }else
      if(loc.x>width)
      {
        
        v.x*=-1;
      }
    if(loc.y>height)
    {
      
      v.y*=-1;
    }else if(loc.y<0)
    {
      
      v.y*=-1;
    }
  }
}