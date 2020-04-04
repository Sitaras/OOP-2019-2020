#include <iostream>
#include <cstdlib>
#include "ask3.h"

using namespace std;

int Object::number=1;
/* static variables that count the Compartments */
int PassengerCompartment::numpass=0;
int EquipmentCompartment::numeq=0;
int CargoBay::numc=0;

/////////////////////////////Object//////////////////////////////

Object::Object() : id(number++){
        cout<< "Object just created!" << endl;
}
Object::Object(int i) : id(i){
        cout<< "Object just created!" << endl;
}

Object::~Object(){
        cout<<"Object to be destroyed!" << endl;
}

/////////////////////////////Plane-Component//////////////////////////////
PlaneComponent::PlaneComponent()
: Security_check(0),Clean_check(0),Maintenance_check(0){
        cout<<"PlaneComponent just created!"<<endl;
}

PlaneComponent::PlaneComponent(int tid,int sc,int cc,int mc)
: Object(tid),Security_check(sc),Clean_check(cc),Maintenance_check(mc){
        cout<<"PlaneComponent just created!"<<endl;
}

PlaneComponent::~PlaneComponent(){
        cout<<"PlaneComponent to be destroyed!"<<endl;
}

/////////////////////////////Passenger-Compartment//////////////////////////////
PassengerCompartment::PassengerCompartment(int i) : in(NULL),ok(i) {
        numpass++;
        if(ok && (rand() % 2)) { /* Interior Space  */
                cout<<"Interior Passenger Compartment just created!"<<endl<<endl<<endl<<endl;
                in=new PassengerCompartment(0); /* (ok==0) -> I don't want the Interior space has an Interior space... */
        }
        cout<<"Passenger Compartment just created!"<<endl<<endl;
}

PassengerCompartment::PassengerCompartment(int tid,int sc, int cc, int mc,int i)
        : PlaneComponent(tid,sc,cc,mc),in(NULL),ok(i){
        numpass++;
        if(ok && (rand() % 2)) { /* Interior Space  */
                cout<<"Interior Passenger Compartment just created!"<<endl<<endl<<endl<<endl;
                in=new PassengerCompartment(0); /* (ok==0) -> I don't want the Interior space has an Interior space... */
        }
        cout<<"Passenger Compartment just created!"<<endl<<endl;
}

PassengerCompartment::~PassengerCompartment(){
        cout<<"Passenger Compartment to be destroyed!"<<endl;
        if(in!=NULL) { /* If Interior Space exists, delete it */
                delete in;
                in=NULL;
        }
}

Object* PassengerCompartment::clone() const {
        /* Create a clone of "this"(Object) and return it */
        PassengerCompartment* pc=new PassengerCompartment(id,Security_check,Clean_check,Maintenance_check,0);
        if (in!=NULL) { /* Interior Space clone */
                pc->in=(PassengerCompartment *)in->clone();
        }
        numpass--;
        return pc;
}

void PassengerCompartment::process(Employee& e){
        /* Assign this compartment to the employee to work */
        e.workon(this);
        if(in!=NULL)
                e.workon(in); /* Interior Space */
}


int PassengerCompartment::ready_check(){
/* Check if Security and Cleaning Employee passed from here */
/* If they passed return 1 else 0 */

        if (Security_check && Clean_check ) {
                if(get_in()!=NULL) {
                        if(get_in()->ready_check()) {
                                Mystring dec=toString();
                                cout<<endl<<endl<< "~~~~~~Description of Passenger Compartment~~~~~~" <<endl<<endl;
                                dec.print();
                                cout<<endl<< "----Interior Space of Passenger Compartment OK!----"<<endl;
                                cout<< "-----Passenger Compartment OK!----"<<endl<<endl;

                                return 1;
                        }
                        else{
                                return 0;
                        }
                }
                else{
                        Mystring dec=toString();
                        cout<<endl<<endl<< "~~~~~~Description of Passenger Compartment~~~~~~" <<endl<<endl;
                        dec.print();
                        cout<<endl<< "-----Passenger Compartment OK!----"<<endl<<endl;

                        return 1;
                }
        }
        else
                return 0;

}

int PassengerCompartment::identical(const Object* o) const {
        /* Compare the addresses of two objects */
        /* Ι am using downcast */
        if (this==o) {
                PassengerCompartment *pPassengerCompartment=(PassengerCompartment *)&o; /* downcast */

                if(in!=NULL) {
                        if(in->identical(pPassengerCompartment->get_in())) {
                                return 1;
                        }
                        else{
                                return 0;
                        }
                }

                return 1;
        }
        return 0;
}

int PassengerCompartment::equal(const Object& o) const {
        /* Compare all data members */
        /* Ι am using downcast */

        if(id==o.get_id()) {
                PassengerCompartment *pPassengerCompartment=(PassengerCompartment *)&o; /* downcast */

                if(Security_check==pPassengerCompartment->get_Security_check() &&
                   Maintenance_check==pPassengerCompartment->get_Maintenance_check() &&
                   Clean_check==pPassengerCompartment->get_Clean_check()) {
                        if(in!=NULL) {
                                if(in->equal(*(pPassengerCompartment->get_in()))) {
                                        return 1;
                                }
                                else{
                                        return 0;
                                }

                        }
                        return 1;
                }
        }
        return 0;
}

Mystring PassengerCompartment::toString() const {
        /* Description for Passenger Compartment */
        Mystring s("Passenger Compartment: id=");
        s=s.get_str().append(to_string(id));
        if(in!=NULL) { /* Interior Space Description */
                s=s.get_str().append("\n~Interior Space:");
                s.concat(in->toString());
                s=s.get_str().append("\n__________________________________");
        }

        return s;
}

/////////////////////////////Private-Compartment//////////////////////////////
PrivateCompartment::PrivateCompartment(){
        cout << "PrivateCompartement just created!" << endl;
}
PrivateCompartment::PrivateCompartment(int tid,int sc,int cc,int mc)
        : PlaneComponent(tid,sc,cc,mc){
        cout << "PrivateCompartement just created!" << endl;
}

PrivateCompartment::~PrivateCompartment(){
        cout<<"PrivateCompartement to be destroyed!"<<endl;
}

/////////////////////////////Equipment-Compartment//////////////////////////////
EquipmentCompartment::EquipmentCompartment(){
        numeq++;
        cout<<"EquipmentCompartment just created!"<<endl;
}
EquipmentCompartment::EquipmentCompartment(int tid,int sc,int cc,int mc)
        : PrivateCompartment(tid,sc,cc,mc){
        numeq++;
        cout<<"EquipmentCompartment just created!"<<endl;
}
EquipmentCompartment::~EquipmentCompartment(){
        cout<<"EquipmentCompartment to be destroyed!"<<endl;
}

Object* EquipmentCompartment::clone() const {
        /* Create a clone of "this"(Object) and return it */
        EquipmentCompartment* eqc=new EquipmentCompartment(id,Security_check,Clean_check,Maintenance_check);
        numeq--;
        return eqc;
}


void EquipmentCompartment::process(Employee& e){
        /* Assign this compartment to the employee to work */
        e.workon(this);
}

int EquipmentCompartment::ready_check(){
/* Check if Maintenance and Security Employee passed from here */
/* If they passed return 1 else 0 */

        if(Maintenance_check && Security_check) {
                Mystring dec=toString();
                cout<<endl<<endl<< "~~~~~~Description of Equipment Compartment ~~~~~~" <<endl<<endl;
                dec.print();
                cout<<endl<<"----Equipment Compartment OK!----"<<endl<<endl;
                return 1;
        }
        else
                return 0;
}

int EquipmentCompartment::identical(const Object* o) const {
/* Compare the addresses of two objects */
        if (this==o) {
                return 1;
        }
        return 0;
}

int EquipmentCompartment::equal(const Object& o) const {
/* Compare all data members */
/* Ι am using downcast */
        if(id==o.get_id()) {
                EquipmentCompartment *pEquipmentCompartment=(EquipmentCompartment *)&o; /* downcast */

                if(Security_check==pEquipmentCompartment->get_Security_check() &&
                   Maintenance_check==pEquipmentCompartment->get_Maintenance_check() &&
                   Clean_check==pEquipmentCompartment->get_Clean_check()) {
                        return 1;
                }
        }
        return 0;
}


Mystring EquipmentCompartment::toString() const {
        /* Description for Equipment Compartment */
        Mystring s("Equipment Compartment: id=");
        s=s.get_str().append(to_string(id));
        return s;
}


/////////////////////////////Cargo-Bay//////////////////////////////

CargoBay::CargoBay() : eqptr(new EquipmentCompartment){
        numc++;
        cout<<"CargoBay just created!"<<endl;
}

CargoBay::CargoBay(int tid,int sc,int cc,int mc,EquipmentCompartment* eq )
        : PrivateCompartment(tid,sc,cc,mc),eqptr(eq){
        numc++;
        cout<<"CargoBay just created!"<<endl;
}

CargoBay::~CargoBay(){
        delete eqptr;
        cout<<"CargoBay to be destroyed!"<<endl;
}

Object* CargoBay::clone() const {
        /* Create a clone of "this"(Object) and return it */
        CargoBay* cb=new CargoBay(id,Security_check,Clean_check,Maintenance_check,(EquipmentCompartment*)eqptr->clone());
        numc--;
        return cb;
}

void CargoBay::process(Employee& e){
        /* Assign this compartment to the employee to work */
        e.workon(this);
}

int CargoBay::ready_check(){
        /* Check if Maintenance, Security and Cleaning Employee passed from here */
        /* If they passed return 1 else 0 */
        if(Clean_check && Security_check && Maintenance_check && eqptr->ready_check()) {
                Mystring dec=toString();
                cout<<endl<<endl<< "~~~~~~Description of Cargo Bay~~~~~~" <<endl<<endl;
                dec.print();
                cout<<endl<< "----Equipment Compartment of Cargo Bay OK!----"<<endl;
                cout<< "-----Cargo Bay OK!----"<<endl<<endl;
                return 1;
        }
        else
                return 0;

}


int CargoBay::equal(const Object& o) const {
/* Compare all data members */
/* Ι am using downcast */
        if(id==o.get_id()) {
                CargoBay *pCargoBay=(CargoBay *)&o; /* downcast */

                if(Security_check==pCargoBay->get_Security_check() &&
                   Maintenance_check==pCargoBay->get_Maintenance_check() &&
                   Clean_check==pCargoBay->get_Clean_check() &&
                   eqptr->equal(*(pCargoBay->get_eqptr())) )
                {
                        return 1;
                }


        }
        return 0;
}


int CargoBay::identical(const Object* o) const {
/* Compare the addresses of two objects */
/* Ι am using downcast */
        if (this==o) {
                CargoBay *pCargoBay=(CargoBay *)&o; /* downcast */

                if(eqptr->identical(pCargoBay->get_eqptr()) ) {
                        return 1;
                }
        }
        return 0;
}


Mystring CargoBay::toString() const {
        /* Description for CargoBay */
        Mystring s("CargoBay: id=");
        s=s.get_str().append(to_string(id));
        s=s.get_str().append("\n~Cargo's EquipmentCompartment:");
        s.concat(eqptr->toString());
        s=s.get_str().append("\n__________________________________");
        return s;
}
