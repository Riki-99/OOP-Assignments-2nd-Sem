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

        void showAddr(){
            cout<<"The address of this object is : " << this<<endl;
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
    

    p1.showAddr();
    p2.showAddr();
    s1.showAddr();
    s2.showAddr();
    e1.showAddr();
    e2.showAddr();

    return 0;
}