//Create a class called carpark that has int data member for car id, int data member for charge/hour, and float data member for the parked time. Make functions to set data members and show the charges and parked hours of the corresponding car id. Make functions for setting and showing the data members. Member function should be called from other functions.

#include <iostream>
using namespace std;

class carpark{
    int carId;
    int chargePerHour;
    float parkedTime;
    //parkedTime in hours
    public:
        void inputDetails()
        {
            cout<<"Enter car id : ";
            cin>>carId;
            cout<<"Enter charge per hour: ";
            cin>>chargePerHour;
            cout<<"Enter parked time in hours: ";
            cin>>parkedTime;
        };

        void displayDetails()
        {
            cout<<endl<<"Car Id: "<<carId<<endl;
            cout<<"Charge Per Hour: "<<chargePerHour<<endl;
            cout<<"Parked Time (Hours): "<<parkedTime<<endl;
            cout<<"Total charge: "<<parkedTime*chargePerHour<<endl;
        }
};

int main(void)
{
    carpark car1;
    car1.inputDetails();
    car1.displayDetails();
    return 0;
}
