#include <iostream>
using namespace std;

class base{
    public:
        virtual void sound(){
            cout<<"Grrrrrr"<<endl;
        }
};

class derived : public base{
    public:
    void sound(){
        cout<<"Barkbark"<<endl;
    }
};

int main(void)
{
    base *b1;
    derived d1;
    b1 = &d1;
    b1->sound(); // same as (*b1).sound();
    return 0;
}