#include <iostream>
#include <cstdlib>
#include "forum.h"
using namespace std ;


int post::number=1; /* for id of posts */

int th_number() {
  return rand() % 5+1;   /* returns num in [1, 5] */
}

int pos_number(){
  return rand() % 4+1;   /* returns num in [1, 4] */
}

int rand_threads(){ /* with unique themes there is not
                             problem to print a specific theme */
    static int themescount=0;
    if (themescount>n_of_themes-1) /* I avoid going overboard array size */
      themescount=0;
    return themescount++;
}

date::date()
:day(rand() % 30 + 1), month(rand() % 12 + 1), year(rand() % 1 + 2019){}



forum::forum(string str)
:title(str), threads(th_number()), th_array(new thread[threads]){

  /* random number of threads (max threads per forum -> 5) */
  /* create the array of threads dynamically */
  /* the array always has at least one thread */

  cout<<"\n* *\n ";
  cout<<"Forum with title:" <<title<< " has just been created! \n";
  cout<<"* *";
  cout<<"\n__________________\n\n";
  /* when these messages print to the screen, construction of the forum has been completed */

}
forum::~forum(){
  cout<<"\n\n\n\n\nForum with title: "<<title<<" is about to be destroyed"<<endl;
  delete[] th_array;

}


thread::thread()
:theme(themes[rand_threads()]),creator(creators[rand()%n_of_creators]), numposts(pos_number()),
po_array(new post[numposts]){

  /* random creator for the thread */
  /* random number of posts (max posts per thread -> 4) */
  /* create the array of posts dynamically */
  /* the array always has at least one post */
  /* no need to initialize x ,x has his own constructor */

  cout<<"\n~ ~\n ";
  cout<<"Thread with subject:" <<theme<< " has just been created! "<<endl;
  cout<<"~ ~\n ";
  cout<<"\n__________________\n";
  /* when these messages print to the screen, construction of one specific thread
     with theme: "theme" has been completed */


}

thread::~thread(){
  cout<<"Thread with subject: "<<theme<<" is about to be destroyed"<<endl;
  delete[] po_array;
}

post::post()
:id(number++),title(titles[rand()%n_of_titles]),
creator(creators[rand()%n_of_creators]),
text(texts[rand()%n_of_texts]), next(NULL){

  /* id must be unique for every post */
  /* random creator for the post */
  /* random text for the post */
  /* random title for the post */
  /* no need to initialize x ,x has his own constructor */

  cout<<"ID."<<id<<"\nDate:"<<x.day<<"/"<<x.month<<"/"<<x.year
      <<"\nTitle:"<<title<<"\nCreator:"
      <<creator<<"\n__________________\n"
      <<text<<endl<<endl;
  cout<<"\n__________________\n";

}
post::~post(){
  cout<<"Post number:"<<id<<" is about to be destroyed"<<endl;

}
