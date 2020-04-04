package Employee_package;
import Plane_Component_package.*;

public class CleaningEmployee extends Employee{


  public CleaningEmployee(String s){
    super(s);
    System.out.println("CleaningEmployee: "+name+ " just created!");
  }

  @Override
  public void workon(PassengerCompartment pc){
    /* Increase the number of Passenger_check every time that Cleaning Employee works at Passenger Compartment */
    /* Also, checks that for this Passenger Compartment worked the Cleaning Employee */
    System.out.println("~Cleaning Employee works in Passenger Compartment.");
    Passenger_check++;
    if(pc.get_Clean_check()==0)
            pc.check_Clean_check();
  }

  @Override
  public void workon(EquipmentCompartment eq){
    System.out.println("~Cleaning Employee doesn't work in Equipment Compartment");
  }

  @Override
  public void workon(CargoBay cb){
  /* Increase the number of CargoBay_check every time that Cleaning Employee works at CargoBay */
  /* Also, checks that for this Cargo Bay worked the Cleaning Employee */
    System.out.println("~Cleaning Employee works in Cargo Bay.");
    CargoBay_check++;
    if(cb.get_Clean_check()==0)
            cb.check_Clean_check();
  }

  public void report(){
  /* Cleaning Employee is OK, if he has worked in all Cargo Bays and */
  /* Passenger Compartments that exists */

    if(CargoBay_check == CargoBay.get_numc() && (CargoBay.get_numc()!=0)) {
            System.out.println("~Cleaning Employee: Cargo Bays OK!");
    }
    if(Passenger_check == PassengerCompartment.get_numpass() && (PassengerCompartment.get_numpass()!=0)) {
            System.out.println("~Cleaning Employee: Passenger Compartments OK!");
    }

  }


  @Override
  public String toString() {
      /* CleaningEmployee Description */
      String stemp=String.format("-Cleaning Employee: id= " + id + "\n Name: " + name);
      return stemp;
  }

  //copy constructor
  public CleaningEmployee(CleaningEmployee ce_old){
    super(ce_old.get_name());
    id=ce_old.get_id();
    CargoBay_check=ce_old.get_CargoBay_check();
    Equipment_check=ce_old.get_Equipment_check();
    Passenger_check=ce_old.get_Passenger_check();
    System.out.println("CleaningEmployee just created by copying!");

  }

  @Override
  public boolean equals(Object obj){
    CleaningEmployee temp=(CleaningEmployee) obj;
    if(id==temp.get_id()){

      if(CargoBay_check==temp.get_CargoBay_check() &&
         Passenger_check==temp.get_Passenger_check() &&
         Equipment_check==temp.get_Equipment_check() &&
         name==temp.get_name()){
           return true;
         }
    }
    return false;
  }


  @Override
  public Object clone(){
    return new CleaningEmployee(this);
  }


}
