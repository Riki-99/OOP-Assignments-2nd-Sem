// e) Conversion from liter to gallons

#include <iostream>
using namespace std;

class ltr{
    private: 
        float value;
    public:
        ltr(float v) : value(v){}
        float getVal(){
            return value;
        }
};

class galloons{
    private:
        float value;
    public:
        galloons(ltr l):value(l.getVal() / 3.7854){}
        void display(){
            cout<<value;
        }
};

int main(void)
{
    float litVal;
    cout<<"Enter ltr value : ";
    cin>>litVal;
    ltr lit(litVal);
    galloons g(lit);
    cout<<"Eqv. galloons: ";
    g.display();
    return 0;
}