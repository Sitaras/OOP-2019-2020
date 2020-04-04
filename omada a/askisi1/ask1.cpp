#include <iostream>
#include "forum.h"
using namespace std ;

int main(void){

  srand(time(NULL)); /* Use current time as seed for random generator */

  forum di("Αντικειμενοστραϕής Προγραμματισμός"); /* creation of the forum */

	di.printforum();

	di.thread_select("Κανόνες και χρήσιμες πληροϕορίες");
  for(int i=1;i<=rand()%10+1;i++)
    di.post_select(rand()%(post::get_num()-1)+1);

  return 0;
}
