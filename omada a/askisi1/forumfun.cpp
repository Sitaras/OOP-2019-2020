#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "forum.h"

using namespace std ;

///////////////////////////////////////////////////////////

void forum::printforum() const{
  cout<<endl<<"Forum:"<<title<<endl<<endl;
  for(int i=0;i<threads;i++)
    cout<<"Thread:"<<th_array[i].get_theme()<<endl<<
    "~Creator:"<<th_array[i].get_creator()<<endl<<endl<<endl;
}


void forum::thread_select(string str) const{
  int ok=0,i;
  for(i=0;i<threads;i++){
    if(th_array[i].get_theme()==str) /* search for str to threads */
      ok=1;
    if(ok){                          /* finded, stop searching */
      break;
    }
  }

  if(ok){ /* finded, print the thread */
    date y=th_array[i].get_x();
    cout<<"THREAD FOUNDED!\n=================\nThread Theme:"
    <<th_array[i].get_theme()<<"\nCreator:"
    <<th_array[i].get_creator()<<"\nDate:"
    <<y.day<<"/"<<y.month<<"/"<<y.year
    <<"\n__________________\n"
    <<"POSTS OF THREAD:"
    <<"\n__________________\n";


    th_array[i].printposts(); /* print the posts of this thread */

  }
  else
    cout<<"Thread:"<<str<<" not found!";

  cout<<endl<<endl<<endl;

}



void forum::post_select(int num) const{
  int flag=0;
  for(int i=0;i<threads;i++){
    flag=th_array[i].search_post(num);

    if(flag)                           /* finded, stop searching */
      break;
  }
  if(!flag)
    cout<<"-->Post with ID:"<<num<<" doesn't exist"<<endl<<endl;

}

/////////////////////////////////////////////////////////////////////////////

void thread::printposts() const{
  for(int i=0;i<numposts;i++){

    date y=po_array[i].get_x();

    cout<<"No."<<po_array[i].get_id()<<"\nDate:"
    <<y.day<<"/"<<y.month<<"/"<<y.year<<"\nTitle:"
    <<po_array[i].get_title()
    <<"\nCreator:"<<po_array[i].get_creator()
    <<"\n__________________\n"
    <<po_array[i].get_text()<<endl<<endl
    <<"\n__________________\n";
  }

}



int thread::search_post(int num) const{
    int i,flag=0;
    for(i=0;i<numposts;i++){
      if(po_array[i].get_id()==num){ /* finded, stop searching */
        flag=1;
        break;
      }
    }
    if(flag==1){     /* finded, print the post */
      date y=po_array[i].get_x();
      cout<<"POST FOUNDED!\n=================\n"
          <<"No."<<po_array[i].get_id()<<"\nDate:"<<y.day<<"/"<<y.month<<"/"<<y.year<<"\nTitle:"
          <<po_array[i].get_title()<<"\nCreator:"<<po_array[i].get_creator()
          <<"\n__________________\n"
          <<po_array[i].get_text()<<endl<<endl
          <<"\n__________________\n";
    }

    return flag;
}
