#include <iostream>
#include <cstdlib>
#include "ask3.h"

using namespace std;

int Plane::rand_PassCompartments(){
        static int i=(rand()%3)+2; /* Plane Passenger Compartments range [2,4] */
        return i;
}


Plane::Plane(string s,int c) :
        title(s)
        ,capacity(c)
        ,pcptr(new PassengerCompartment* [rand_PassCompartments()])
        ,cargoptr(new CargoBay)
        ,eqptr(new EquipmentCompartment* [3])
{
        for(int i=0; i<rand_PassCompartments(); i++)
                pcptr[i]=new PassengerCompartment;

        for(int i=0; i<3; i++)
                eqptr[i]=new EquipmentCompartment;

        cout<<endl<<endl<<"Plane: ";
        title.print();
        cout<< "Just created!"<<endl<<"~Capacity:"<<capacity<<endl<<endl;

}

Plane::Plane(int tid,string s,int c) :
        Object(tid)
        ,title(s)
        ,capacity(c)
        ,pcptr(new PassengerCompartment* [rand_PassCompartments()])
        ,cargoptr(NULL)
        ,eqptr(new EquipmentCompartment* [3])
{
        for(int i=0; i<rand_PassCompartments(); i++)
                pcptr[i]=NULL;

        for(int i=0; i<3; i++)
                eqptr[i]=NULL;

        cout<<endl<<endl<<"Plane: ";
        title.print();
        cout<< "Just created!"<<endl<<"~Capacity:"<<capacity<<endl<<endl;
}

Plane::~Plane(){
        cout<<"Plane to be destroyed!"<<endl;
        delete cargoptr;
        for(int i=0; i<3; i++)
                delete eqptr[i];
        delete[] eqptr;
        for(int i=0; i<rand_PassCompartments(); i++)
                delete pcptr[i];
        delete[] pcptr;
}


Object* Plane::clone() const {
/* Create a clone of "this"(Object) and return it */
/* I have to clone all the Plane Compartments of "this"  */
        Plane* p=new Plane(id,title.get_str(),capacity);

        for(int i=0; i<rand_PassCompartments(); i++) {
                p->pcptr[i]=(PassengerCompartment *)pcptr[i]->clone();
        }

        p->cargoptr=(CargoBay *)cargoptr->clone();

        for(int i=0; i<3; i++) {
                p->eqptr[i]=(EquipmentCompartment *)eqptr[i]->clone();
        }

        return p;

}


int Plane::equal(const Object& o) const {
/* Compare all data members */
/* Ι am using downcast */

        int flag=1;

        if(id==o.get_id()) {
                Plane *pPlane=(Plane *)&o; /* downcast */

                for(int i=0; i<rand_PassCompartments(); i++) {
                        if(pcptr[i]->equal(*(pPlane->get_pcptr()[i]))==0) {
                                flag=0;
                                break;
                        }
                }
                if(title.get_str()==pPlane->get_title().get_str()
                   && capacity==pPlane->get_capacity()
                   && cargoptr->equal(*(pPlane->get_cargoptr()))
                   && eqptr[0]->equal(*(pPlane->get_eqptr()[0]))
                   && eqptr[1]->equal(*(pPlane->get_eqptr()[1]))
                   && eqptr[2]->equal(*(pPlane->get_eqptr()[2]))
                   && flag ) {

                        return 1;
                }
        }
        return 0;
}


int Plane::identical(const Object* o) const {
/* Compare the addresses of two objects and the addresses of all Compartments */
/* Ι am using downcast */
        if (this==o) {
                int flag=1;

                Plane *pPlane=(Plane *)o;   /* downcast */

                for(int i=0; i<rand_PassCompartments(); i++) {
                        if(pcptr[i]->identical((pPlane->get_pcptr()[i]))==0) {
                                flag=0;
                                break;
                        }
                }
                if(cargoptr->identical((pPlane->get_cargoptr()))
                   && eqptr[0]->identical((pPlane->get_eqptr()[0]))
                   && eqptr[1]->identical((pPlane->get_eqptr()[1]))
                   && eqptr[2]->identical((pPlane->get_eqptr()[2]))
                   && flag ) {

                        return 1;
                }

        }
        return 0;
}


Mystring Plane::toString() const {
        /* Description for plane */
        Mystring s("Plane: id=");
        s=s.get_str().append(to_string(id));
        s=s.get_str().append(" Title:");
        s.concat(title);
        s=s.get_str().append(" Capacity:");
        s=s.get_str().append(to_string(capacity));
        /* For the compartments I call their own toStrings
           and then join them to the original (one by one) */
        for(int i=0; i<rand_PassCompartments(); i++)
                s.concat(pcptr[i]->toString());
        s.concat(cargoptr->toString());
        for(int i=0; i<3; i++)
                s.concat(eqptr[i]->toString());

        return s;
}

void Plane::process(SecurityEmployee& e){
/* Plane Compartments:Cargo Bay,Passenger Compartment and Equipment Compartment */
/* At these Plane Compartments provided Security Employee to works */

        cout<<endl<<"~Security Employee is in the plane!"<<endl<<endl;

        cargoptr->process(e);

        cargoptr->get_eqptr()->process(e); /* Cargo's Bay Equipment Compartment */

        for(int i=0; i<rand_PassCompartments(); i++) {
                pcptr[i]->process(e);
        }

        for(int i=0; i<3; i++) {
                eqptr[i]->process(e);
        }

}

void Plane::process(MaintenanceEmployee& e){
/* Plane Compartments:Cargo Bay and Equipment Compartment */
/* At these Plane Compartments provided Maintenance Employee to works */

        cout<<endl<<"~Maintenance Employee is in the plane!"<<endl<<endl;

        cargoptr->process(e);

        cargoptr->get_eqptr()->process(e); /* Cargo's Bay Equipment Compartment */

        for(int i=0; i<3; i++) {
                eqptr[i]->process(e);
        }

}

void Plane::process(CleaningEmployee& e){
/* Plane Compartments:Cargo Bay and Passenger Compartment */
/* At these Plane Compartments provided Cleaning Employee to works */

        cout<<endl<<"~CleaningEmployee Employee is in the plane!"<<endl<<endl;

        for(int i=0; i<rand_PassCompartments(); i++) {
                pcptr[i]->process(e);
        }

        cargoptr->process(e);


}

void Plane::ready_check(){
/* Check all Compartments if they have provided to them the suitable Employees */
/* Yes, then the plane is ready to take off */

        int flag=1;
        for(int i=0; i<rand_PassCompartments(); i++) {
                if(pcptr[i]->ready_check()==0) {
                        flag=0;
                        break;
                }
        }

        if(flag && cargoptr->ready_check() &&
           eqptr[0]->ready_check() && eqptr[1]->ready_check() && eqptr[2]->ready_check())
                cout<<endl<<endl<<"~~~~~~~~Plane ready to take off!~~~~~~~~"<<endl<<endl;
        else
                cout<<endl<<endl<<"~~~~~~~~Plane is NOT ready to take off!~~~~~~~~"<<endl<<endl;

}
