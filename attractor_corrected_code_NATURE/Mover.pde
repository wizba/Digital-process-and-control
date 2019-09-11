class c 
{
 
  private PVector v2;
  private PVector L,a;
  
  PVector f;
  float m;
  float rSquire;
  float massSqure;
  public c()
  {
    
    v2=new PVector(0,0);
    a=new PVector(0.01,0);
    L=new PVector(random(6,350),random(6,350));
    m=random(1.5,5);
    
    
  }
 
  void update()
  {
    
    PVector dir=PVector.sub(f,L);
    dir.setMag(0.05);
    a=dir.div(m/2);
    
    v2.add(a);
    v2.limit(10);
    L.add(v2);
    
  }
  
  void object()
  {
    ellipse(L.x,L.y,10*m,10*m);
  }
  void forceRecive(attractor A)
  {
     f=A.aloc;
         
  }
}