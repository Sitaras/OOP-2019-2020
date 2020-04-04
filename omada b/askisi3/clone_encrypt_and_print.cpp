#include <iostream>
#include <cstdlib>
#include "ask3.h"

using namespace std;

void clone_encrypt_and_print(Object& ob){

        cout<<endl<<"_______________________________________________"<<endl;
        cout<<endl<<"           (clone_encrypt_and_print)    "<<endl;
        cout<<endl<<"_______________________________________________"<<endl;

        Object* cloneob=ob.clone(); /* clone creation */

        if(ob.equal(*cloneob))
                cout<<endl<<"--------Objects are equal!--------"<<endl<<endl;
        else
                cout<<endl<<"--------Objects are NOT equal!--------"<<endl<<endl;


        if(ob.identical(cloneob))
                cout<<endl<<"--------Objects are Identical!--------"<<endl<<endl;
        else
                cout<<endl<<"--------Objects are  NOT Identical!--------"<<endl<<endl;

        Mystring strclone=cloneob->toString();
        Mystring stroriginal=ob.toString();

        cout<<endl<<endl<< "~~~~~~Descriptions~~~~~~" <<endl<<endl;
        strclone.print();
        cout<<endl<<endl;
        stroriginal.print();

        string temp1,temp2;
        int pos1,pos2;
        
        for(int i=0; i<11; i++) {
                pos1=rand() % strclone.length();
                temp1=strclone.at(pos1);
                pos2=rand() % strclone.length();
                temp2=strclone.at(pos2);
                strclone.updateAt(pos2,temp1);
                strclone.updateAt(pos1,temp2);
        }
        cout<<endl<<endl<<"~~~~~~Strings after changing characters positions of clone string.~~~~~~"<<endl<<endl;
        strclone.print();
        cout<<endl<<endl;
        stroriginal.print();

        cout<<endl<<endl<<"~~~~~~Unite the Strings~~~~~~"<<endl<<endl;

        Mystring strunion=stroriginal;
        strunion.concat(strclone);
        strunion.print();
        cout<<endl<<"~~~~~~Length of union: "<<strunion.length()<<endl<<endl;

        if(strunion.length() % 2==0) { /* if length is even number print one character */
                cout<<"Mid character:"<<endl;
                temp1=strunion.at(strunion.length()/2);
                cout<<temp1<<endl;

        }
        else{ /* else two characters */
                cout<<"~~~~~~Mid characters:"<<endl<<endl;
                temp1=strunion.at((int)strunion.length()/2);
                temp2=strunion.at((int)strunion.length()/2+1);
                cout<<temp1<<","<<temp2<<endl;
        }

        cout<<endl<<"~~~~~~Clear out the union.~~~~~~"<<endl<<endl;
        strunion.clear();
        cout<<endl<<"~~~~~~Length of union: "<<strunion.length()<<endl<<endl;

        delete cloneob; /* virtual destructor of Object */

}
