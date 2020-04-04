#include <iostream>
#include "ask3.h"

using namespace std;

/////////////////////////////Employee/////////////////////////////
Employee::Employee(string s) : name(s)
        ,CargoBay_check(0)
        ,Equipment_check(0)
        ,Passenger_check(0)
{
        cout<<"Employee just created!"<<endl;
}
Employee::Employee(int tid,int cb,int eq,int ps,string s) :
        Object(tid)
        ,name(s)
        ,CargoBay_check(cb)
        ,Equipment_check(eq)
        ,Passenger_check(ps)
{
        cout<<"Employee just created!"<<endl;
}


Employee::~Employee(){
        cout << "Employee to be destroyed " <<endl;
}

Mystring Employee::toString() const {
        /* Description for Employee */
        Mystring s("id=");
        s=s.get_str().append(to_string(id));
        s=s.get_str().append(" Νame:");
        s.concat(name);
        return s;
}

/////////////////////////////Security-Employee/////////////////////////////

SecurityEmployee::SecurityEmployee(string s) : Employee(s){
        cout << "Security Employee just created!" << endl;
        cout <<"Name: "<<name.get_str()<<endl<<endl;
}
SecurityEmployee::SecurityEmployee(int tid,int cb,int eq,int ps,string s) : Employee(tid,cb,eq,ps,s){
        cout << "Security Employee just created!" << endl;
        cout <<"Name: "<<name.get_str()<<endl<<endl;
}

SecurityEmployee::~SecurityEmployee(){
        cout<<"Security Employee to be destroyed!"<<endl;
}

void SecurityEmployee::workon(PassengerCompartment* pc){
/* Increase the number of Passenger_check every time that Security Employee works at one PassengerCompartment */
/* Also, checks that for this Passenger Compartment worked the Security Employee */

        cout<<"~Security Employee works in Passenger Compartment with id:"<<pc->get_id()<<endl;
        Passenger_check++;
        if(pc->get_Security_check()==0)
                pc->check_Security_check();
}

void SecurityEmployee::workon(EquipmentCompartment* ec){
/* Increase the number of Equipment_check every time that Security Employee works at one EquipmentCompartment */
/* Also, checks that for this Equipment Compartment worked the Security Employee */

        cout<<"~Security Employee works in Equipment Compartment with id:"<<ec->get_id()<<endl;
        Equipment_check++;
        if(ec->get_Security_check()==0)
                ec->check_Security_check();
}

void SecurityEmployee::workon(CargoBay* cb){
/* Increase the number of CargoBay_check every time that Security Employee works at one CargoBay */
/* Also, checks that for this Cargo Bay worked the Security Employee */

        cout<<"~Security Employee works in Cargo Bay with id:"<<cb->get_id()<<endl;
        CargoBay_check++;
        if(cb->get_Security_check()==0)
                cb->check_Security_check();
}


void SecurityEmployee::report(){
/* Security Employee is OK, if he has worked in all Plane Compartments that exists */

        if(CargoBay_check==CargoBay::get_numc() && CargoBay::get_numc()!=0) {
                cout<<"~Security Employee: Cargo Bays OK!"<<endl;
        }
        if(Equipment_check==EquipmentCompartment::get_numeq() && EquipmentCompartment::get_numeq()!=0) {
                cout<<"~Security Employee: Equipment Compartments OK!"<<endl;
        }
        if(Passenger_check==PassengerCompartment::get_numpass() && PassengerCompartment::get_numpass()!=0) {
                cout<<"~Security Employee: Passenger Compartments OK!"<<endl;
        }

}
int SecurityEmployee::identical(const Object* o) const {
/* Compare the addresses of two objects */

        if (this==o) {
                return 1;
        }
        return 0;
}

int SecurityEmployee::equal(const Object& o) const {
/* Compare all data members */
/* Ι am using downcast */

        if(id==o.get_id()) {

                SecurityEmployee *pSecurityEmployee=(SecurityEmployee *)&o; /* downcast */

                if(name.get_str()==pSecurityEmployee->get_name().get_str() &&
                   CargoBay_check==pSecurityEmployee->get_CargoBay_check() &&
                   Equipment_check==pSecurityEmployee->get_Equipment_check() &&
                   Passenger_check==pSecurityEmployee->get_Passenger_check()) {
                        return 1;
                }
        }
        return 0;
}

Object* SecurityEmployee::clone() const {
/* Create a clone of "this"(Object) and return it */
        SecurityEmployee* se=new SecurityEmployee(id,CargoBay_check,Equipment_check,Passenger_check,name.get_str());
        return se;
}

/////////////////////////////Maintenance-Employee/////////////////////////////

MaintenanceEmployee::MaintenanceEmployee(string s) : Employee(s){
        cout << "Maintenance Employee just created!" << endl;
        cout <<"Name: "<<name.get_str()<<endl<<endl;
}
MaintenanceEmployee::MaintenanceEmployee(int tid,int cb,int eq,int ps,string s) : Employee(tid,cb,eq,ps,s){
        cout << "Maintenance Employee just created!" << endl;
        cout <<"Name: "<<name.get_str()<<endl<<endl;
}

MaintenanceEmployee::~MaintenanceEmployee(){
        cout<<"Maintenance Employee to be destroyed!"<<endl;
}

void MaintenanceEmployee::workon(PassengerCompartment* pc){
        cout<<"~Maintenance Employee doesn't work in Passenger Compartment"<<endl;
}

void MaintenanceEmployee::workon(EquipmentCompartment* eq){
/* Increase the number of Equipment_check every time that Maintenance Employee works at one EquipmentCompartment */
/* Also, checks that for this Equipment Compartment worked the Maintenance Employee */

        cout<<"~Maintenance Employee works in Equipment Compartment with id:"<<eq->get_id()<<endl;
        Equipment_check++;
        if(eq->get_Maintenance_check()==0)
                eq->check_Maintenance_check();
}

void MaintenanceEmployee::workon(CargoBay* cb){
/* Increase the number of CargoBay_check every time that Maintenance Employee works at one CargoBay */
/* Also, checks that for this Cargo Bay worked the Maintenance Employee */

        cout<<"~Maintenance Employee works in Cargo Bay with id:"<<cb->get_id()<<endl;
        CargoBay_check++;
        if(cb->get_Maintenance_check()==0)
                cb->check_Maintenance_check();
}


void MaintenanceEmployee::report(){
/* Maintenance Employee is OK, if he has worked in all Cargo Bays and
   Equipment Compartments that exists */

        if(CargoBay_check==CargoBay::get_numc() && CargoBay::get_numc()!=0) {
                cout<<"~Maintenance Employee: Cargo Bays OK!"<<endl;
        }
        if(Equipment_check==EquipmentCompartment::get_numeq() && EquipmentCompartment::get_numeq()!=0) {
                cout<<"~Maintenance Employee: Equipment Compartments OK!"<<endl;
        }
}

int MaintenanceEmployee::identical(const Object* o) const {
/* Compare the addresses of two objects */

        if (this==o) {
                return 1;
        }
        return 0;
}

int MaintenanceEmployee::equal(const Object& o) const {
/* Compare all data members */
/* Ι am using downcast */

        if(id==o.get_id()) {

                MaintenanceEmployee *pMaintenanceEmployee=(MaintenanceEmployee *)&o; /* downcast */

                if(name.get_str()==pMaintenanceEmployee->get_name().get_str() &&
                   CargoBay_check==pMaintenanceEmployee->get_CargoBay_check() &&
                   Equipment_check==pMaintenanceEmployee->get_Equipment_check() &&
                   Passenger_check==pMaintenanceEmployee->get_Passenger_check()) {
                        return 1;
                }
        }
        return 0;
}

Object* MaintenanceEmployee::clone() const {
/* Create a clone of "this"(Object) and return it */
        MaintenanceEmployee* me=new MaintenanceEmployee(id,CargoBay_check,Equipment_check,Passenger_check,name.get_str());
        return me;
}

/////////////////////////////Cleaning-Employee/////////////////////////////

CleaningEmployee::CleaningEmployee(string s) : Employee(s){
        cout << "Cleaning Employee just created!" << endl;
        cout <<"Name: "<<name.get_str()<<endl<<endl;
}


CleaningEmployee::CleaningEmployee(int tid,int cb,int eq,int ps,string s) : Employee(tid,cb,eq,ps,s){
        cout << "Cleaning Employee just created!" << endl;
        cout <<"Name: "<<name.get_str()<<endl<<endl;
}

CleaningEmployee::~CleaningEmployee(){
        cout<<"Cleaning Employee to be destroyed!"<<endl;
}

void CleaningEmployee::workon(PassengerCompartment* pc){
/* Increase the number of Passenger_check every time that Cleaning Employee works at Passenger Compartment */
/* Also, checks that for this Passenger Compartment worked the Cleaning Employee */
        cout<<"~Cleaning Employee works in Passenger Compartment with id:"<<pc->get_id()<<endl;
        Passenger_check++;
        if(pc->get_Clean_check()==0)
                pc->check_Clean_check();

}

void CleaningEmployee::workon(EquipmentCompartment* eq){
        cout<<"~Cleaning Employee doesn't work in Equipment Compartment"<<endl;
}

void CleaningEmployee::workon(CargoBay* cb){
/* Increase the number of CargoBay_check every time that Cleaning Employee works at CargoBay */
/* Also, checks that for this Cargo Bay worked the Cleaning Employee */

        cout<<"~Cleaning Employee works in Cargo Bay with id:"<<cb->get_id()<<endl;
        CargoBay_check++;
        if(cb->get_Clean_check()==0)
                cb->check_Clean_check();

}


void CleaningEmployee::report(){
/* Cleaning Employee is OK, if he has worked in all Cargo Bays and
   Passenger Compartments that exists */
        if(CargoBay_check==CargoBay::get_numc() && CargoBay::get_numc()!=0) {
                cout<<"~Cleaning Employee: Cargo Bays OK!"<<endl;
        }
        if(Passenger_check==PassengerCompartment::get_numpass() && PassengerCompartment::get_numpass()!=0) {
                cout<<"~Cleaning Employee: Passenger Compartments OK!"<<endl;
        }

}

int CleaningEmployee::identical(const Object* o) const {
/* Compare the addresses of two objects */

        if (this==o) {
                return 1;
        }
        return 0;
}

int CleaningEmployee::equal(const Object& o) const {
/* Compare all data members */
/* Ι am using downcast */

        if(id==o.get_id()) {

                CleaningEmployee *pCleaningEmployee=(CleaningEmployee *)&o; /* downcast */

                if(name.get_str()==pCleaningEmployee->get_name().get_str() &&
                   CargoBay_check==pCleaningEmployee->get_CargoBay_check() &&
                   Equipment_check==pCleaningEmployee->get_Equipment_check() &&
                   Passenger_check==pCleaningEmployee->get_Passenger_check()) {
                        return 1;
                }
        }
        return 0;
}

Object* CleaningEmployee::clone() const {
        /* Create a clone of "this"(Object) and return it */
        CleaningEmployee* ce=new CleaningEmployee(id,CargoBay_check,Equipment_check,Passenger_check,name.get_str());
        return ce;
}
