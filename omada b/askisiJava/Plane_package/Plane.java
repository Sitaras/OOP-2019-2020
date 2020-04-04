package Plane_package;

import java.util.Random; /* to generate random numbers */
import Employee_package.*;
import Plane_Component_package.*;

public class Plane {

private int id;
private String title;
private int capacity;
private int Plane_Compartments;
private PassengerCompartment[] pc;
private CargoBay cb;
private EquipmentCompartment[] eq;

/* ----------------------------------- */


 public Plane(String s){
  Random rand = new Random();
  id=this.hashCode(); /* unique */
  title=s;
  capacity=rand.nextInt(101)+100; /* range [100,200] */
  Plane_Compartments=rand.nextInt(3)+2;  /* Plane Compartments range [2,4] */

  pc=new PassengerCompartment[Plane_Compartments];
  for (int i=0; i<Plane_Compartments; i++){
     pc[i]=new PassengerCompartment(1);
   }

  cb=new CargoBay();

  eq=new EquipmentCompartment[3];
  for (int i=0; i<3; i++){
     eq[i]=new EquipmentCompartment();
   }
  System.out.println("\n\nPlane: " + title +" just created!\n");
}


public void process(SecurityEmployee e){
/* Plane Compartments:Cargo Bay,Passenger Compartment and Equipment Compartment */
/* At these Plane Compartments provided Security Employee to works */

  System.out.println("\n~Security Employee is in the plane!\n");

  cb.process(e);

  cb.get_eq().process(e); /* Cargo's Bay Equipment Compartment */

  for (int i=0; i<Plane_Compartments; i++){
    pc[i].process(e);

  }

  for (int i=0; i<3; i++){
    eq[i].process(e);
  }

}
public void process(MaintenanceEmployee e){
/* Plane Compartments: Cargo Bay and Equipment Compartment */
/* At these Plane Compartments provided Maintenance Employee to works */

        System.out.println("\n~Maintenance Employee is in the plane!\n");

        cb.process(e);

        cb.get_eq().process(e); /* Cargo's Bay Equipment Compartment */

        for (int i=0; i<3; i++){
          eq[i].process(e);
        }

}
public void process(CleaningEmployee e){
/* Plane Compartments: Cargo Bay and Passenger Compartment */
/* At these Plane Compartments provided Cleaning Employee to works */
        System.out.println("\n~CleaningEmployee Employee is in the plane!\n");

        for (int i=0; i<Plane_Compartments; i++){
          pc[i].process(e);
        }

        cb.process(e);

}
public void ready_check(){
/* Check all Compartments if they have provided to them the suitable Employees */
/* Yes, then the plane is ready to take off */

        int flag=1;
        for (int i=0; i<Plane_Compartments; i++){
          if(pc[i].ready_check()==0) {
                  flag=0;
                  break;
          }
        }

        if(flag==1 && cb.ready_check()==1 &&
           eq[0].ready_check()==1 && eq[1].ready_check()==1 && eq[2].ready_check()==1)
           System.out.println("\n~~~~~~~~Plane ready to take off!~~~~~~~~\n");
        else
           System.out.println("\n~~~~~~~~Plane NOT ready to take off!~~~~~~~~\n");

}

@Override
public String toString() {
  /* Plane Description */
    String stemp=String.format("Plane: id=" + id +"\nTitle: "+ title +"\nCapacity: "+capacity);

    /* Description for Passengers Compartments */
    for (int i=0; i<Plane_Compartments; i++){
      stemp=stemp.concat("\n"+pc[i].toString());
    }

    /* Description for Cargo Bays */
    stemp=stemp.concat("\n"+cb.toString());

    /* Description for Equipment Compartments */
    for (int i=0; i<3; i++){
      stemp=stemp.concat("\n"+eq[i].toString());
    }

    return stemp;
}

//copy constructor
public Plane(Plane pl_old){

  id=pl_old.get_id();
  title=pl_old.get_title();
  capacity=pl_old.get_capacity();
  Plane_Compartments=pl_old.get_Plane_Compartments();

  pc=new PassengerCompartment[Plane_Compartments];
  for (int i=0; i<Plane_Compartments; i++){
     pc[i]=(PassengerCompartment) pl_old.get_pc()[i].clone();
   }

   cb=(CargoBay) pl_old.get_cb();

   eq=new EquipmentCompartment[3];
   for (int i=0; i<3; i++){
      eq[i]=(EquipmentCompartment) pl_old.get_eq()[i].clone();
    }
   System.out.println("\n\nPlane: " + title +" just created by copy!\n");

}

@Override
public boolean equals(Object obj){
  Plane temp=(Plane) obj;

  if(id==temp.get_id()){

    if(title==temp.get_title() &&
       capacity==temp.get_capacity() &&
       Plane_Compartments==temp.get_Plane_Compartments() &&
       cb.equals(temp.get_cb()) ){
         for(int i=0;i<Plane_Compartments;i++){
           if(pc[i].equals(temp.get_pc()[i])==false)
            return false;
         }
         for(int i=0;i<3;i++){
           if(eq[i].equals(temp.get_eq()[i])==false)
            return false;
         }

         return true;
       }
  }
  return false;
}

@Override
public Object clone(){
    return new Plane(this);
}

public String get_title(){
  return title;
}

public int get_capacity(){
  return capacity;
}

public int get_Plane_Compartments(){
  return Plane_Compartments;
}

public PassengerCompartment[] get_pc(){
  return pc;
}

public CargoBay get_cb(){
  return cb;
}

public int get_id(){
  return id;
}

public EquipmentCompartment[] get_eq(){
  return eq;
}

}
