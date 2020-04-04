package Plane_Component_package;
import Employee_package.*;

public class EquipmentCompartment extends PrivateCompartment{

  private static int numeq;

/* ------------------------------ */

  public EquipmentCompartment(){
      numeq++;
      System.out.println("EquipmentCompartment just created!");

  }

  public int ready_check(){
  /* Check if Maintenance and Security Employee passed from here */
  /* If they passed return 1 else 0 */
          if(Maintenance_check==1 && Security_check==1) {
                  System.out.println(this.toString());
                  System.out.println("\n----Equipment Compartment OK!----\n");
                  return 1;
          }
          else
                  return 0;
  }

  @Override
  public void process(Employee e){
      /* Assign this compartment to the employee to work */
      e.workon(this);
  }

  //copy constructor
  public EquipmentCompartment(EquipmentCompartment eq_old){
    id=eq_old.get_id();
    Security_check=eq_old.get_Security_check();
    Maintenance_check=eq_old.get_Maintenance_check();
    Clean_check=eq_old.get_Clean_check();
    System.out.println("EquipmentCompartment just created by copying!");
  }

  @Override
  public boolean equals(Object obj){
    EquipmentCompartment temp=(EquipmentCompartment) obj;
    if(id==temp.get_id()){
      
      if(Security_check==temp.get_Security_check() &&
         Clean_check==temp.get_Clean_check() &&
         Maintenance_check==temp.get_Maintenance_check()){
           return true;
         }
    }
    return false;
  }

  @Override
  public Object clone(){
      return new EquipmentCompartment(this);
  }


  @Override
  public String toString() {
      /* Equipment Compartment Description */
      String stemp=String.format("-Equipment Compartment: id=" + id);
      return stemp;
  }


  public static int get_numeq(){
    return numeq;
  }

}
