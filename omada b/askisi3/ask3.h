#ifndef  __ASK3__
#define  __ASK3__
using std::string;

class Object;
class Mystring;
class Employee;
class CargoBay;
class Plane;
class EquipmentCompartment;
class PassengerCompartment;
class SecurityEmployee;
class MaintenanceEmployee;
class CleaningEmployee;


void clone_encrypt_and_print(Object&);

class Object {
protected:
  int id;
private:
  static int number;
public:
  Object();
  Object(int);
  virtual ~Object();

  int get_id() const;

  virtual Object* clone() const=0;
  virtual int equal(const Object&) const=0;
  virtual int identical(const Object*) const=0;
  virtual Mystring toString() const=0;
};


class Mystring : public Object {
private:
  string str;
public:
  Mystring();
  Mystring(string);
  Mystring(int,string);
  ~Mystring();

  int length() const;
  void clear();
  void concat(const Mystring&);
  char at(int) const;
  void updateAt(int,string);
  void print() const;

  string get_str() const;

  Object* clone() const;
  int equal(const Object&) const;
  int identical(const Object*) const;
  Mystring toString() const;


};


class Plane : public Object {
private:
  Mystring title;
  int capacity;

  PassengerCompartment** pcptr;
  CargoBay* cargoptr;
  EquipmentCompartment** eqptr;

  static int rand_PassCompartments();
public:
  Plane(string ,int=(rand() % 191)+10); // default parameter for capacity -> range[10,200]
  Plane(int,string,int=(rand() % 191)+10);
  ~Plane();

  PassengerCompartment** get_pcptr() const;
  CargoBay* get_cargoptr() const;
  EquipmentCompartment** get_eqptr() const;
  int get_capacity() const;
  Mystring get_title() const;

  void ready_check();
  /* function overloading */
  void process(SecurityEmployee&);
  void process(MaintenanceEmployee&);
  void process(CleaningEmployee&);

  Object* clone() const;
  int equal(const Object&) const;
  int identical(const Object*) const;
  Mystring toString() const;
};


class PlaneComponent : public Object {
protected:
  int Security_check;
  int Clean_check;
  int Maintenance_check;

public:
  PlaneComponent();
  PlaneComponent(int,int,int,int);
  virtual ~PlaneComponent();

  virtual int ready_check()=0;
  virtual void process(Employee&)=0;

  int get_Security_check() const;
  int get_Clean_check() const;
  int get_Maintenance_check() const;

  void check_Security_check();
  void check_Clean_check();
  void check_Maintenance_check();

};

class PassengerCompartment : public PlaneComponent {
  private:
    PassengerCompartment* in;
    int ok; /* ensures that creates one interior space */
    static int numpass;
  public:
    PassengerCompartment(int=1);
    PassengerCompartment(int,int,int,int,int=1);
    ~PassengerCompartment();

    int ready_check();
    void process(Employee&);

    PassengerCompartment* get_in() const;
    static int get_numpass() ;

    Mystring toString() const;
    Object* clone() const;
    int equal(const Object&) const;
    int identical(const Object*) const;

};


class PrivateCompartment : public PlaneComponent {
  private:

  public:
    PrivateCompartment();
    PrivateCompartment(int,int,int,int);
    ~PrivateCompartment();
};

class EquipmentCompartment : public PrivateCompartment {
  private:
    static int numeq;
  public:
    EquipmentCompartment();
    EquipmentCompartment(int,int,int,int);
    ~EquipmentCompartment();

    int ready_check();
    void process(Employee&);

    static int get_numeq();

    Mystring toString() const;
    Object* clone() const;
    int equal(const Object&) const;
    int identical(const Object*) const;
};


class CargoBay : public PrivateCompartment{
  private:
    EquipmentCompartment *eqptr;
    static int numc;

  public:
    CargoBay();
    CargoBay(int,int,int,int,EquipmentCompartment*);
    ~CargoBay();

    int ready_check();
    void process(Employee&);

    EquipmentCompartment* get_eqptr() const;
    static int get_numc();

    Mystring toString() const;
    Object* clone() const;
    int equal(const Object&) const;
    int identical(const Object*) const;
};


class Employee : public Object {
protected:
    Mystring name;
    int CargoBay_check;
    int Equipment_check;
    int Passenger_check;
public:
   Employee(string);
   Employee(int,int,int,int,string);
   virtual ~Employee();

   virtual void report()=0;
   /* function overloading */
   virtual void workon(PassengerCompartment*)=0;
   virtual void workon(EquipmentCompartment*)=0;
   virtual void workon(CargoBay*)=0;

   Mystring toString() const;

   Mystring get_name() const;
   int get_CargoBay_check() const;
   int get_Equipment_check() const;
   int get_Passenger_check() const;
};


class SecurityEmployee : public Employee {
  private:

   public:
    SecurityEmployee(string);
    SecurityEmployee(int,int,int,int,string);
    ~SecurityEmployee();

    void report();
    void workon(PassengerCompartment*);
    void workon(EquipmentCompartment*);
    void workon(CargoBay*);

    Object* clone() const;
    int equal(const Object&) const;
    int identical(const Object*) const;
};


class MaintenanceEmployee : public Employee {
  private:

  public:
    MaintenanceEmployee(string);
    MaintenanceEmployee(int,int,int,int,string);
    ~MaintenanceEmployee();

    void report();
    void workon(PassengerCompartment*);
    void workon(EquipmentCompartment*);
    void workon(CargoBay*);

    Object* clone() const;
    int equal(const Object&) const;
    int identical(const Object*) const;
};



class CleaningEmployee : public Employee {
  private:

  public:
    CleaningEmployee(string);
    CleaningEmployee(int,int,int,int,string);
    ~CleaningEmployee();

    void report();
    void workon(PassengerCompartment*);
    void workon(EquipmentCompartment*);
    void workon(CargoBay*);

    Object* clone() const;
    int equal(const Object&) const;
    int identical(const Object*) const;
};

#endif
