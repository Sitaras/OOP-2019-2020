package Plane_Component_package;
import java.util.Random;
import Employee_package.*;


public class PassengerCompartment extends PlaneComponent {
private PassengerCompartment in;
private int ok; /* ensures that creates one interior space */
private static int numpass;

/* ------------------------------ */

public PassengerCompartment(int i){
  numpass++;
  ok=i;
  Random rand = new Random();

  if(ok == 1 && rand.nextInt(2)!=0 ) {
      System.out.println("Interior Passenger Compartment just created!");
      in=new PassengerCompartment(0);
  }
  System.out.println("PassengerCompartment just created!");

}

@Override
public void process(Employee e){
/* Assign this compartment to the employee to work */
  e.workon(this);
  if(in!=null)
          e.workon(in);
}

public int ready_check(){
/* Check if Security and Cleaning Employee passed from here */
/* If they passed return 1 else 0 */
  if(Security_check==1 && Clean_check==1){
    if(in!=null){
      if(in.ready_check()==1){
        System.out.println(this.toString());
        System.out.println("\n----Interior Space of Passenger Compartment OK!----");
        System.out.println("-----Passenger Compartment OK!-----\n");
        return 1;
      }
    }
    else{
      System.out.println(this.toString());
      System.out.println("\n-----Passenger Compartment OK!-----\n");
      return 1;
    }

  }
    return 0;
}

@Override
public String toString() {
    /* Passenger Compartment Description */
    String stemp=String.format("-Passenger Compartment: id=" + id);
    if(in!=null)
      stemp=stemp.concat("\n>>>Interior Space of "+in.toString());

    return stemp;
}

//copy constructor
public PassengerCompartment(PassengerCompartment pc_old){

  if(pc_old.get_in()!=null)
    in=(PassengerCompartment) pc_old.get_in().clone();
  else
    in=null;

  id=pc_old.get_id();
  ok=pc_old.get_ok();
  Security_check=pc_old.get_Security_check();
  Maintenance_check=pc_old.get_Maintenance_check();
  Clean_check=pc_old.get_Clean_check();
  System.out.println("PassengerCompartment just created by copying!");
}

@Override
public boolean equals(Object obj){
  PassengerCompartment temp=(PassengerCompartment) obj;
  if(id==temp.get_id()){

    if(Security_check==temp.get_Security_check() &&
       Clean_check==temp.get_Clean_check() &&
       Maintenance_check==temp.get_Maintenance_check()){
         if(in!=null){
           if(in.equals(temp.get_in()))
            return true;
           else
            return false;
         }
         return true;
       }
  }
  return false;
}

@Override
public Object clone(){
    return new PassengerCompartment(this);
}


public PassengerCompartment get_in(){
  return in;
}

public int get_ok(){
  return ok;
}

public static int get_numpass(){
  return numpass;
}

}
