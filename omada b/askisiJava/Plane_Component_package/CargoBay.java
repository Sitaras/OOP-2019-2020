package Plane_Component_package;
import Employee_package.*;

public class CargoBay extends PrivateCompartment{

  private EquipmentCompartment eq;
  private static int numc;

/* ------------------------------ */

  public CargoBay(){
    numc++;
    eq=new EquipmentCompartment();
    System.out.println("CargoBay just created!");
}

  @Override
  public void process(Employee e){
  /* Assign this compartment to the employee to work */
    e.workon(this);
  }

  public int ready_check(){
  /* Check if Maintenance, Security and Cleaning Employee passed from here */
  /* If they passed return 1 else 0 */
    if(Clean_check==1 &&
        Security_check ==1 &&
        Maintenance_check==1 &&
        eq.ready_check()==1 ) {
          System.out.println(this.toString());
          System.out.println("\n----Equipment Compartment of Cargo Bay OK!----");
          System.out.println("-----Cargo Bay OK!----\n");
          return 1;
  }
  else {
    return 0;
  }
}

@Override
public String toString() {
    /* Cargo Bay Description */
    String stemp=String.format("-Cargo Bay: id=" + id);
    stemp=stemp.concat("\n>>>Cargo Bay's Equipment Compartment"+eq.toString());

    return stemp;
}

//copy constructor
public CargoBay(CargoBay cb_old){
  id=cb_old.get_id();
  eq=(EquipmentCompartment) cb_old.get_eq().clone();
  Security_check=cb_old.get_Security_check();
  Maintenance_check=cb_old.get_Maintenance_check();
  Clean_check=cb_old.get_Clean_check();
  System.out.println("CargoBay just created by copying!");

}

@Override
public boolean equals(Object obj){
  CargoBay temp=(CargoBay) obj;
  if(id==temp.get_id()){
    
    if(Security_check==temp.get_Security_check() &&
       Clean_check==temp.get_Clean_check() &&
       Maintenance_check==temp.get_Maintenance_check() &&
       eq.equals(temp.get_eq()) ){
         return true;
       }
  }
  return false;
}


@Override
public Object clone(){
    return new CargoBay(this);
}

public static int get_numc(){
  return numc;
}
public EquipmentCompartment get_eq(){
  return eq;
}

}
