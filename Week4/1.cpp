//Write a program that has a class to represent time. The class should have constructors to initialize data members hour, min, and sec to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.

#include <iostream>

using namespace std;

class time{
    private:
        int hour;
        int min;
        int sec;
    public:
        time(){
            hour = 0;
            min = 0;
            sec = 0;
        }

        void convert()
        {
            while(sec >= 60)
            {
                min++;
                sec -=60;
            }
            while(min >= 60)
            {
                hour++;
                min -=60;
            }
            while(hour >= 24)
                hour-=24;
        }

        time add(time t){
            time tmp;
            tmp.sec = t.sec + sec;
            tmp.min = t.min + min;
            tmp.hour = t.hour + hour;
            tmp.convert();
        }

        void display(int hrSpecs)
        {
            convert();
            if(hrSpecs == 12)
            {
                int flag = 0;
                if(hour > 12)
                {
                    hour -=12;
                    flag = 1;
                }
                else{
                    cout<<hour<<" : "<<min<<" : "<<sec<<((flag)?"PM" : "AM");
                }

            }

            else{
                cout<<hour<<" : "<<min<<" : "<<sec;
            }
        }
};

int main(void)
{
    time t;
    return 0;
}
