#include <iostream>
using namespace std;

class Student{
    protected:
        int studentNum;
    public: 
        virtual void showField() = 0;
};

class Engineering : public Student{
    public:
        void showField(){
            cout<<"Engineering" <<endl;
        }
};

class Medicine : public Student{
    public:
        void showField(){
            cout<<"Medicine" <<endl;
        }
};

class Science : public Student{
    public:
        void showField(){
            cout<<"Science" <<endl;
        }
};


int main(void)
{
    Student* s[3];
    Engineering e; Medicine m; Science sc;
    s[0] = &e; s[1] = &m; s[2] = &sc;
    for(int i = 0; i <3; i++)
    {
        s[i]->showField();
    }
    return 0;
}