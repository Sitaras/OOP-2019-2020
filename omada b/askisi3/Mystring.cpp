#include <iostream>
#include "ask3.h"

using namespace std;

Mystring::Mystring(string s) : str(s) {
        cout<<"Mystring just created!"<<endl;
}
Mystring::Mystring(int tid,string s) : Object(tid),str(s) {
        cout<<"Mystring just created!"<<endl;
}
Mystring::Mystring(){
        cout<<"Mystring just created!"<<endl;
}
Mystring::~Mystring() {
        cout << "\nMystring to be destroyed!" << endl;
}

Mystring Mystring::toString() const {
        /* Description for Mystring */
        Mystring s("id=");
        s=s.str.append(to_string(id));
        return s;
}

int Mystring::equal(const Object& o) const {
/* Compare all data members */
/* I am using downcast */
        if(id==o.get_id()) {
                Mystring *pMystring=(Mystring *)&o; /* downcast */

                if(str==pMystring->get_str()) {
                        return 1;
                }
        }
        return 0;
}

int Mystring::identical(const Object* o) const {
/* Compare the addresses of two objects */
        if (this==o) {
                return 1;
        }
        return 0;
}

Object* Mystring::clone() const {
/* Create a clone of "this"(Object) and return it */
        Mystring* s=new Mystring(id,str);
        return s;

}

int Mystring::length() const {
        return str.length();
}

void Mystring::clear() {
        str.clear();
}

void Mystring::concat(const Mystring& s)  {
        str.append("\n");
        str.append(s.str);
}

char Mystring::at(int i) const {
        return str.at(i);
}

void Mystring::updateAt(int i,string ch) {
        str.replace(i,1,ch);
}


void Mystring::print() const {
        cout <<">>>"<<str<<"<<<"<<endl;
}
