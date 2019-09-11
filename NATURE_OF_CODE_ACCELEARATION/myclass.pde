class c
{
  private PVector v1;
  private PVector v2;
  private PVector L,a;
  float f;
  public c()
  {
    
    v2=new PVector(0,0);
    a=new PVector(0.01,0);
    L=new PVector(random(6,350),random(6,350));
    f=random(0.5,3);
  }
 
  void calc()
  {
    PVector mouse=new PVector(mouseX,mouseY);
    PVector dir=PVector.sub(mouse,L);
    dir.setMag(0.5);
    a=dir;
    
    v2.add(a);
    v2.limit(10);
    L.add(v2);
    
  }
  
  void object()
  {
    ellipse(L.x,L.y,50,50);
  }
}