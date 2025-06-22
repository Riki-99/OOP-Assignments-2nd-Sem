//Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.


#include <iostream>
using namespace std;

class Time {
private:
    int hour, min, sec;

public:
    Time() : hour(0), min(0), sec(0) {}

    Time(int h, int m, int s) : hour(h), min(m), sec(s) {
        normalize();
    }

    void normalize() {
        if (sec >= 60) {
            min += sec / 60;
            sec %= 60;
        }
        if (min >= 60) {
            hour += min / 60;
            min %= 60;
        }
        if (hour >= 24) {
            hour %= 24;
        }
    }

    Time add(const Time& t) {
        Time tmp;
        tmp.sec = sec + t.sec;
        tmp.min = min + t.min;
        tmp.hour = hour + t.hour;
        tmp.normalize();
        return tmp;
    }

    void display(int format) {
        normalize();
        if (format == 12) {
            int displayHour = hour % 12;
            if (displayHour == 0) displayHour = 12;
            cout << (displayHour < 10 ? "0" : "") << displayHour << " : "
                 << (min < 10 ? "0" : "") << min << " : "
                 << (sec < 10 ? "0" : "") << sec
                 << (hour >= 12 ? " PM" : " AM") << endl;
        } else {
            cout << (hour < 10 ? "0" : "") << hour << " : "
                 << (min < 10 ? "0" : "") << min << " : "
                 << (sec < 10 ? "0" : "") << sec << endl;
        }
    }
};

int main() {
    Time t1(10, 45, 50);
    Time t2(2, 30, 25);
    Time t3 = t1.add(t2);

    cout << "Time in 24-hour format: ";
    t3.display(24);

    cout << "Time in 12-hour format: ";
    t3.display(12);

    return 0;
}
