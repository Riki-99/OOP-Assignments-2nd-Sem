//a) Conversion from Kg to pound system.

#include <iostream>
using namespace std;

class kg{
    private:
        float value;
    public:
        void set(){
            cin>>value;
        }
        float get(){
            return value;
        }
};

class pound{
    private:
        float value;
    public:
        pound(kg k) : value(k.get()*2.205){}
        float get(){
            return value;
        }
};

int main(void)
{
    cout<<"Enter weight in kgs: ";
    kg wt1;
    wt1.set();
    pound p = pound(wt1);
    cout<<"Wt in pound : "<<p.get();
    return 0;
}