//Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.

#include <iostream>
using namespace std;

class Month{
    public:
        int days;
};

Month m[12];

class Date{
    private:
        int day, month, year;
    public:
        Date(int y, int m, int d) : year(y),  month(m), day(d){}
        void operator ++(int){
            day++;
            if(isLeap(year)) m[1].days = 29;
            if (day > m[month-1].days)
            {
                day-=m[month-1].days;
                month++;
            }

            if (month>12)
            {
                year++;
                month-=12;
            }
            m[1].days = 28;
        }

        void operator --(int){
            day--;
            if(isLeap(year)) m[1].days = 29;
            if (day <= 0)
            {
                int prevMonthCt; 
                if(month-2 >= 0 && month-2 <=11) prevMonthCt = m[(month-1)-1].days;
                if(month-2 < 0) prevMonthCt = m[11].days;
                day+=prevMonthCt;
                month--;
            }

            if (month<=0)
            {
                year--;
                month+=12;
            }
            m[1].days = 28;
        }

        void display()
        {
            cout<<year<<"/"<<month<<"/"<<day<<endl;
        }
        bool isLeap(int y)
        {
            if((y%400 == 0) || (y%4 == 0 && y%100 != 0))
                return true;
            return false;
        }
};

int main(void)
{
    int idx;
    for(int i = 0; i < 12; i++)
    {
        idx = i+1;
        if(idx == 4 || idx == 6 || idx == 9 || idx == 11)
            {
                m[i].days = 30;
            }
        else if (idx == 2)
            {
                m[i].days = 28;
            }
        else{
            m[i].days = 31;
            }
            // cout<<i << " " << i+1 << " "<< m[i].days <<endl;
    }



    Date d1(2021,3,1);
    d1--;
    d1.display();
    d1++;
    d1.display();
    return 0;    
}
