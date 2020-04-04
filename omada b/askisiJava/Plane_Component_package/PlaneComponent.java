package Plane_Component_package;
import Employee_package.*;



public abstract class PlaneComponent{
  protected int id; /* unique */
  protected int Security_check;
  protected int Clean_check;
  protected int Maintenance_check;
  public abstract int ready_check();
  public abstract void process(Employee e);

  /* ---------------------------------------- */

  public PlaneComponent(){
    id=this.hashCode();
    Security_check=0;
    Clean_check=0;
    Maintenance_check=0;
    System.out.println("PlaneComponent just created!");
  }

  public int get_Security_check(){
    return Security_check;
  }
  public int get_Clean_check(){
    return Clean_check;
  }
  public int get_Maintenance_check(){
    return Maintenance_check;
  }

  public int get_id(){
    return id;
  }

  public void check_Security_check(){
    Security_check=1;
  }
  public void check_Clean_check(){
    Clean_check=1;
  }
  public void check_Maintenance_check(){
    Maintenance_check=1;
  }

}
