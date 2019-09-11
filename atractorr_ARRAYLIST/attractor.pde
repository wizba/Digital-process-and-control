class Attractor
{
  public PVector l;
  private attracted A=new attracted();
  
  public Attractor()
  {
    l=new PVector(width/2,height/2);
  }
  
  void attractorDraw()
  {
    fill(0,255,0);
    ellipse(l.x,l.y,50,50);
  }
 
  PVector acc()
  {
    l=new PVector(mouseX,mouseY);
    
    PVector ret=PVector.sub(l,A.loc);
    
   
  
    return ret;
  }
}