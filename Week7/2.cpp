#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
    public:
        void inputDetails(){
            cout<<"Enter name : ";
            cin>>name;
        }
        void showName(){
            cout<<"Name : "<<name<<endl;
        }
};

class Student : virtual public Person{
    private:
        float gpa;
    public:
        void showDetails(){
            showName();
            cout<<"GPA : "<< gpa<<endl;
        }

        void inputDetails(){
            Person::inputDetails();
            cout<<"Enter GPA: ";
            cin>>gpa;
        }
};

class Employee : virtual public Person{
    private:
        float salary;
    public:
        void showDetails(){
            showName();
            cout<<"Salary : "<< salary<<endl;
        }

        void inputDetails(){
            Person::inputDetails();
            cout<<"Enter Salary: ";
            cin>>salary;
        }
};

class Manager : public Student, public Employee{
    public:
        void showDetails(){
            // Virtual base class results in no conflicts between the two parent classes and 
            // only one copy is obtained from the grandparent to this granchild.
            showName();
            cout<<"Post : Manager"<<endl;
        }

        void inputDetails(){
            Person::inputDetails();
        }
};

int main(void)
{
    Student s;
    Employee e;
    Manager m;
        m.inputDetails();
        m.showDetails();
}