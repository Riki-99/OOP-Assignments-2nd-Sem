//Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.


#include <iostream>

using namespace std;

class test{
    private:
        static int serial_number;
    public:
        test(){
            serial_number++;
            cout<<"Object number "<<serial_number<<" created "<<endl;
        }

        static void display(){
            cout<<"Current count: "<< serial_number<<endl;
        }
};

int test::serial_number = 0;

int main(void)
{
    test t1;
    test::display();
    test t2;
    test::display();
    return 0;
}