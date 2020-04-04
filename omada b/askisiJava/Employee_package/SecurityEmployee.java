package Employee_package;
import Plane_Component_package.*;


public class SecurityEmployee extends Employee{


  public SecurityEmployee(String s){
    super(s);
    System.out.println("SecurityEmployee: "+name+ " just created!");
  }

  @Override
  public void workon(PassengerCompartment pc){
    /* Increase the number of Passenger_check every time that Security Employee works at one PassengerCompartment */
    /* Also, checks that for this Passenger Compartment worked the Security Employee */
    System.out.println("~Security Employee works in Passenger Compartment.");
    Passenger_check++;
    if(pc.get_Security_check()==0)
            pc.check_Security_check();
  }

  @Override
  public void workon(EquipmentCompartment ec){
    /* Increase the number of Equipment_check every time that Security Employee works at one EquipmentCompartment */
    /* Also, checks that for this Equipment Compartment worked the Security Employee */
    System.out.println("~Security Employee works in Equipment Compartment.");
    Equipment_check++;
    if(ec.get_Security_check()==0)
            ec.check_Security_check();
  }

  @Override
  public void workon(CargoBay cb){
    /* Increase the number of CargoBay_check every time that Security Employee works at one CargoBay */
    /* Also, checks that for this Cargo Bay worked the Security Employee */
    System.out.println("~Security Employee works in Cargo Bay.");
    CargoBay_check++;
    if(cb.get_Security_check()==0)
            cb.check_Security_check();
  }



  public void report(){
  /* Security Employee is OK, if he has worked in all Plane Compartments that exists */

    if(CargoBay_check ==  CargoBay.get_numc() && (CargoBay.get_numc()!=0)) {
            System.out.println("~Security Employee: Cargo Bays OK!");
    }
    if(Equipment_check == EquipmentCompartment.get_numeq() && (EquipmentCompartment.get_numeq()!=0)) {
            System.out.println("~Security Employee: Equipment Compartments OK!");
    }
    if(Passenger_check == PassengerCompartment.get_numpass() && (PassengerCompartment.get_numpass()!=0)) {
            System.out.println("~Security Employee: Passenger Compartments OK!");
    }

  }

  @Override
  public String toString() {
    /* SecurityEmployee Description */
    String stemp=String.format("-Security Employee: id= " + id + "\n Name: " + name);
    return stemp;
  }

  //copy constructor
  public SecurityEmployee(SecurityEmployee sc_old){
    super(sc_old.get_name());
    id=sc_old.get_id();
    CargoBay_check=sc_old.get_CargoBay_check();
    Equipment_check=sc_old.get_Equipment_check();
    Passenger_check=sc_old.get_Passenger_check();
    System.out.println("SecurityEmployee just created by copying!");
  }

  @Override
  public boolean equals(Object obj){
    SecurityEmployee temp=(SecurityEmployee) obj;
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
    return new SecurityEmployee(this);
  }

}
