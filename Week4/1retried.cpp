//Write a program that has a class to represent Time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add Time objects and return the result as a Time object. There should be functions to display Time in 12-hour and 24-hour format.

#include <iostream>
using namespace std;

class Time{
    private:
        int hour;
        int min;
        int sec;
    public:
        Time(): hour(0), min(0), sec(0){}
        Time(int h, int m, int s) : hour(h), min(m), sec(s){
            standardize();
        }

        void standardize()
        {
            if(sec>=60)
            {
                min+=sec/60;
                sec%=60;
            }

            if(min>=60)
            {
                hour+=min/60;
                min%=60;
            }

            if(hour>=24)
            {
                hour%=24;
            }
         }

        Time add(Time t)
        {
            Time tmp;
            tmp.sec = t.sec + sec;
            tmp.min = t.min + min;
            tmp.hour = t.hour + hour;
            tmp.standardize();
            return tmp;
        }

        void display(int format)
        {
            standardize();
            if(format == 12)
            {
                int dispHour;
                dispHour = hour%12;
                if(hour == 0) dispHour = 12;
                cout<<((dispHour < 10)? "0" : "")<<dispHour<< " : " 
                << (min < 10 ? "0" : "") << min << " : "<<
                (sec<10 ? "0" : "") << sec << (hour >= 12? " PM" : " AM")<<endl;
            }
            else{
                 cout<<((hour < 10)? "0" : "")<<hour<< " : " 
                 << (min < 10 ? "0" : "") << min << " : "<<
                 (sec<10 ? "0" : "") << sec <<endl;
            }
        }
};

int main(void)
{
    Time t1(2,50,12);
    Time t2(10,14,0);
    Time t3;
    t3 = t1.add(t2);
    t3.display(12);
    t3.display(24);
}
