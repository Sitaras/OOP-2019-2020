#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ask3.h"

using namespace std;

int main(void){

srand(time(NULL));

cout<<endl<<">~~~~Plane Creation.~~~~<"<<endl<<endl;

Plane pl("AIRBUS A320");

cout<<endl<<endl<<endl;
cout<<endl<<">~~~~Employees Creation.~~~~<"<<endl<<endl;

SecurityEmployee se("Panos");
MaintenanceEmployee me("Dimitris");
CleaningEmployee ce("Emily");

cout<<endl<<">~~~~Each employee is provided on the plane to work on it.~~~~<"<<endl<<endl;
pl.process(se);
pl.process(me);
pl.process(ce);

cout<<endl<<">~~~~Each employee makes a report of his work.~~~~<"<<endl<<endl;
se.report();
me.report();
ce.report();


cout<<endl<<">~~~~Confirmation of readiness to take off the Plane.~~~~<"<<endl<<endl;
pl.ready_check();


clone_encrypt_and_print(pl);

return 0;
}
