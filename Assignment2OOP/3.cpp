//c) Conversion from meter system to feet system.

#include <iostream>
using namespace std;

class meter{
    private:
        float value;
    public:
        void ipt(){
            cin>>value;
        }
        float getVal(){
            return value;
        }
};

class feet{
    private:
        float value;
    public:
    feet(meter m):value(m.getVal() * 3.28){}
    void show(){
        cout<<value;
    }
};

int main(void)
{
    meter m1;
    cout<<"Enter meter value: ";
    m1.ipt();
    feet f1(m1);
    cout<<"Feet eqv value: ";
    f1.show();
    return 0;
}