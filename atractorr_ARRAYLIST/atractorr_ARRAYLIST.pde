attracted A[]=new attracted[200];
ArrayList <attracted> name=new ArrayList<attracted>();
Attractor B;
int i=0;
void setup()
{
  size(800,600); 
}

void draw()
{
 

  background(0);

  
  noStroke();
  for(attracted m:name)
  {
    
    m.forceAccumulator(B.acc());
    B.attractorDraw();
    m.calcs();
    m.showShape();
    m.edges();
  }
}
void keyPressed()
{

    B=new Attractor();
    name.add(new attracted());
    
}