import Plane_package.*;
import Employee_package.*;

public class Main {

public static void main(String[] args) {

  System.out.println("\n\n>~~~~Plane Creation.~~~~<\n\n");
  Plane pl =new Plane("AIRBUS A320");

  System.out.println("\n\n>~~~~Description of Plane.~~~~<\n\n");

  System.out.println(pl.toString());

  System.out.println("\n\n>~~~~Employees Creation.~~~~<\n\n");
  SecurityEmployee se = new SecurityEmployee("George");
  MaintenanceEmployee me = new MaintenanceEmployee("Dimitris");
  CleaningEmployee ce = new CleaningEmployee("Emily");

  System.out.println("\n\n>~~~~Each employee is provided on the plane to work on it.~~~~<\n\n");
  pl.process(se);
  pl.process(me);
  pl.process(ce);

  System.out.println("\n\n>~~~~Each employee makes a report of his work.~~~~<\n\n");

  se.report();
  ce.report();
  me.report();

  System.out.println("\n\n>~~~~Confirmation of readiness to take off the Plane.~~~~<\n\n");

  pl.ready_check();

  }

}
