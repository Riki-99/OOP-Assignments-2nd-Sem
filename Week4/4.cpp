//Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).

#include <iostream>

using namespace std;

class vehicle_charge{
    private:
        int num_vehicle, hour;
        float rate;
    public:
    vehicle_charge(vehicle_charge &v){
        num_vehicle = v.num_vehicle;
        hour = v.hour;
        rate = v.rate;
    }

    vehicle_charge(int n, int h, float r) : num_vehicle(n), hour(h), rate(r){}
    
    void display(){
        float charge = rate*hour*num_vehicle;
        charge = (num_vehicle > 10)? charge: charge*0.9;
        cout<<"Charge is : "<<charge<<endl;
    }
};

int main(void)
{
    vehicle_charge v1(5, 10, 5.5);
    vehicle_charge v2 = vehicle_charge(v1);
    v2.display();
}