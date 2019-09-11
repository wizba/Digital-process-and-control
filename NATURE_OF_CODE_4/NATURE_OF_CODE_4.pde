physics []phys;
void setup()
{

  size(630,360);
  phys=new physics[5];
  for(int i=0;i<phys.length;i++)
  {     phys[i]=new physics();}
}
void draw()
{
  background(0);
  for(physics p:phys)
  {
    PVector f=new PVector(0,0.3); 
    p.forceAccumulator(f.mult(p.mass));
    if(mousePressed)
    {
    PVector wind=new PVector(0.2,0);
    p.forceAccumulator(wind);
    }
    p.myObj();
    p.calcPos();
    p.checkEdges();
    
  }

}