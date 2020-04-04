#include <iostream>
#include "forum.h"
using namespace std ;

int main(void){

  srand(time(NULL)); /* Use current time as seed for random generator */

  forum di("Αντικειμενοστραϕής Προγραμματισμός"); /* creation of the forum */

  di.print_sorted();


  return 0;
}
