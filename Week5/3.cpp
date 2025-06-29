//Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.

#include <iostream>
using namespace std;

class student{
    private:
        float marks;
    public:

        student(float m) : marks(m){}
        int operator <(student s2)
        {
            if(marks < s2.marks)
                return 1;
            return 0;
        }

        int operator >(student s2)
        {
            if(marks > s2.marks)
                return 1;
            return 0;
        }
        int operator ==(student s2)
        {
            if(marks ==  s2.marks)
                return 1;
            return 0;
        }

        int operator !=(student s2)
        {
            if(marks !=  s2.marks)
                return 1;
            return 0;
        }

        int operator <=(student s2)
        {
            if(marks <=  s2.marks)
                return 1;
            return 0;
        }

        int operator >=(student s2)
        {
            if(marks >=  s2.marks)
                return 1;
            return 0;
        }
};

int main(void)
{
    student s1(12);
    student s2(20);
    cout<<"s1 < s2: " <<(s1<s2)<<endl;
    cout<<"s1 > s2: " <<(s1>s2)<<endl;
    cout<<"s1 == s2: " <<(s1==s2)<<endl;
    cout<<"s1 != s2: " <<(s1!=s2)<<endl;
    cout<<"s1 <= s2: " <<(s1<=s2)<<endl;
    cout<<"s1 >= s2: " <<(s1>=s2)<<endl;
    return 0;
}