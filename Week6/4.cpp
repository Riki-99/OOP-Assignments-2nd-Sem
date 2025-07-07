//Write three derived classes inheriting functionality of base class person (should have a member function that asks to enter name and age) and with added unique features of student, and employee, and functionality to set properties of student and employee objects. And make one member function for printing the address of the objects of classes (base and derived) using this pointer. Create two objects of the base class and the derived classes each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by each object and verify this with address spaces printed by the program.


#include <iostream>
using namespace std;

class person{
    protected:
        string name;
        int age;
    public:
        void inputCredentials(){
            cout<<"Enter name : ";
            cin>>name;
            cout<<"Enter age: ";
            cin>>age;
        }

        person* Addr(){
            return this;
        }
};

class student : public person{
    private:
        int grade;
    public:
        void inputGrade(){
            inputCredentials();
            cout<<"Enter grade : ";
            cin>>grade;
        }
};

class employee : public person{
    private:
        int panID;
    public:
        void inputPanId(){
            inputCredentials();
            cout<<"Enter pan ID : ";
            cin>>panID;
        }
};

int main(void)
{
    person p1, p2;
    student s1, s2;
    employee e1, e2;
    cout<<"For student : "<<endl;
    s1.inputGrade();

    cout<<"For employee: "<<endl;
    e1.inputPanId();
    

    cout<<(p1.Addr()- p2.Addr());
    cout<<(s1.Addr() - s2.Addr());
    cout<<(e1.Addr() - e2.Addr());

    return 0;
}