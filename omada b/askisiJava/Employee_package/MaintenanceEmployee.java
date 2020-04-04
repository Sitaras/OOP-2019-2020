package Employee_package;
import Plane_Component_package.*;

public class MaintenanceEmployee extends Employee{


  public  MaintenanceEmployee(String s){
    super(s);
    System.out.println("MaintenanceEmployee: "+name+ " just created!");
  }

  @Override
  public void workon(PassengerCompartment pc){
    System.out.println("~Maintenance Employee doesn't work in Passenger Compartment");
  }

  @Override
  public void workon(EquipmentCompartment eq){
    /* Increase the number of Equipment_check every time that Maintenance Employee works at one EquipmentCompartment */
    /* Also, checks that for this Equipment Compartment worked the Maintenance Employee */
    System.out.println("~Maintenance Employee works in Equipment Compartment.");
    Equipment_check++;
    if(eq.get_Maintenance_check()==0)
            eq.check_Maintenance_check();
  }

  @Override
  public void workon(CargoBay cb){
    /* Increase the number of CargoBay_check every time that Maintenance Employee works at one CargoBay */
    /* Also, checks that for this Cargo Bay worked the Maintenance Employee */
    System.out.println("~Maintenance Employee works in Cargo Bay.");
    CargoBay_check++;
    if(cb.get_Maintenance_check()==0)
            cb.check_Maintenance_check();
  }


  public void report(){
  /* Maintenance Employee is OK, if he has worked in all Cargo Bays and
     Equipment Compartments that exists */
    if(CargoBay_check == CargoBay.get_numc() && (CargoBay.get_numc()!=0) ) {
            System.out.println("~Maintenance Employee: Cargo Bays OK!");
    }
    if(Equipment_check == EquipmentCompartment.get_numeq() && (EquipmentCompartment.get_numeq()!=0) ) {
            System.out.println("~Maintenance Employee: Equipment Compartments OK!");
    }

  }

  @Override
  public String toString() {
    /* MaintenanceEmployee Description */
    String stemp=String.format("-Maintenance Employee: id= " + id + "\n Name: " + name);
    return stemp;
  }

  //copy constructor
  public MaintenanceEmployee(MaintenanceEmployee me_old){
    super(me_old.get_name());
    id=me_old.get_id();
    CargoBay_check=me_old.get_CargoBay_check();
    Equipment_check=me_old.get_Equipment_check();
    Passenger_check=me_old.get_Passenger_check();
    System.out.println("MaintenanceEmployee just created by copying!");

  }

  @Override
  public boolean equals(Object obj){
    MaintenanceEmployee temp=(MaintenanceEmployee) obj;
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
    return new MaintenanceEmployee(this);
  }


}
