class attractor
{
  private PVector aloc;
  private float mass;
  private float rad;
  
  attractor()
  {
    mass =5;
    rad=20;
    aloc=new PVector(width/2,height/2);
  }
 
 void attractorDisp()
 {
   ellipse(aloc.x,aloc.y,rad,rad);
 }


}