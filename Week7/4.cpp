#include <iostream>
using namespace std;

class Vehicle{
    virtual void start(){
        cout<<"Vehicle starts";
    }
};

class Bus : public Vehicle{};

class Car : public Vehicle{};

class Bike : public Vehicle{};

int main(void)
{
    Vehicle* v;
    Bus b; Car c; Bike bi;
    v = &b;
    cout<< typeid(*v).name()<<endl;
    v = &c;
    cout<< typeid(*v).name()<<endl;
    v = &bi;
    cout<< typeid(*v).name()<<endl;

    Car* cpt;
    Bike* bipt;

    //Fails type downcast because v is not pointing to car but to bike  
    cpt = dynamic_cast<Car*>(v);
    //Gives valid address becuase v is pointing to Bike
    bipt = dynamic_cast<Bike*>(v);

    cout<<"cpt : " << cpt<<endl;
    cout<<"bipt : " << bipt<<endl;
    return 0;
}