#include <iostream>
#include "ask3.h"
using namespace std;

///////////////////Object///////////////////

int Object::get_id() const {
        return id;
}
///////////////////Mystring///////////////////

string Mystring::get_str() const {
        return str;
}
///////////////////Plane///////////////////
PassengerCompartment** Plane::get_pcptr() const {
        return pcptr;
}

Mystring Plane::get_title() const {
        return title;
}

CargoBay* Plane::get_cargoptr() const {
        return cargoptr;
}
EquipmentCompartment** Plane::get_eqptr() const {
        return eqptr;
}

int Plane::get_capacity() const {
        return capacity;
}
///////////////////Plane-Component///////////////////

int PlaneComponent::get_Security_check() const {
        return Security_check;
}
int PlaneComponent::get_Clean_check() const {
        return Clean_check;
}
int PlaneComponent::get_Maintenance_check() const {
        return Maintenance_check;
}

void PlaneComponent::check_Security_check(){
        Security_check=1;
}
void PlaneComponent::check_Clean_check(){
        Clean_check=1;
}
void PlaneComponent::check_Maintenance_check(){
        Maintenance_check=1;
}


///////////////////Passenger-Compartment///////////////////

PassengerCompartment* PassengerCompartment::get_in() const {
        return in;
}
int PassengerCompartment::get_numpass(){
        return numpass;
}
///////////////////Equipment-Compartment///////////////////

int EquipmentCompartment::get_numeq(){
        return numeq;
}


///////////////////Cargo-Bay///////////////////
int CargoBay::get_numc(){
        return numc;
}

EquipmentCompartment* CargoBay::get_eqptr() const {
        return eqptr;
}

///////////////////Employee///////////////////
Mystring Employee::get_name() const {
        return name;
}
int Employee::get_CargoBay_check() const {
        return CargoBay_check;
}
int Employee::get_Equipment_check() const {
        return Equipment_check;
}
int Employee::get_Passenger_check() const {
        return Passenger_check;
}
