package Employee_package;
import Plane_Component_package.*;

public abstract class Employee {

  protected int id; /* unique */
  protected String name;
  protected int CargoBay_check;
  protected int Equipment_check;
  protected int Passenger_check;

  abstract public void report();
  abstract public void workon(PassengerCompartment pc);
  abstract public void workon(EquipmentCompartment ec);
  abstract public void workon(CargoBay cb);

/* -------------------------------------------------------- */

  Employee(String s){
    id=this.hashCode();
    name=s;
    CargoBay_check=0;
    Equipment_check=0;
    Passenger_check=0;
  }

  public int get_CargoBay_check(){
    return CargoBay_check;
  }

  public int get_Equipment_check(){
    return Equipment_check;
  }

  public int get_Passenger_check(){
    return  Passenger_check;
  }

  public String get_name(){
    return name;
  }

  public int get_id(){
    return id;
  }

}
