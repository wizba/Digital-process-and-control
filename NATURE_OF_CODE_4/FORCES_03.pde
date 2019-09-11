class physics
{
   private PVector velocity;
   private PVector acceleration;
   private PVector displacement;
   public PFont font;
   public float mass;   
   
   physics()
   {
     velocity=new PVector(0,0);
     acceleration=new PVector(0,0);
     displacement=new PVector(random(0,width),height/2);
     mass=random(1,2); 
   }
   
   void forceAccumulator(PVector force)//SIGMA(F)=ma
   {
       PVector f=PVector.div(force,mass);
       acceleration=f;
     
   }
   void calcPos()
   {    
        
        velocity.add(acceleration);
        displacement.add(velocity);
        acceleration.mult(0);
   }
   
   void checkEdges()
   {
      if(displacement.x>width )
      {
        velocity.x*=-1;
       displacement.x=width;
       
      }else
      if(displacement.x<0)
      {
        velocity.x*=-1;
         displacement.x*=-1;
      }
      
      if(displacement.y>height)
      {
        velocity.y*=-1;
       displacement.y=height;
       
      }else
      if(displacement.y<0)
      {
        velocity.x*=-1;
         displacement.y=0;
      }
     
   }
   void myObj()
   {
     
     stroke(255);
     strokeWeight(3);
     ellipse(displacement.x,displacement.y,20*mass,20*mass);
   }
}