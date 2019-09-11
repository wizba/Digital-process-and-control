attracted A[]=new attracted[200];
Attractor B;
void setup()
{
  size(800,600);
  for(int i=0;i<A.length;i++)
  {
    A[i]=new attracted();
    B=new Attractor();
  }
   
}

void draw()
{
 

  background(0);

  
  noStroke();
  for(attracted m:A)
  {
    
    m.forceAccumulator(B.acc());
    B.attractorDraw();
    m.calcs();
    m.showShape();
    m.edges();
  }
}