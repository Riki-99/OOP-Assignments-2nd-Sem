// g) Conversion from the meter/cm to feet/inches
#include <iostream>
using namespace std;

class international{
    private:
        float m, cm;
    public:
        international(float mt, float cmt) : m(mt), cm(cmt){}
        float getm(){return m;}
        float getcm(){return cm;}
};


class fps{
    private:
        float ft, in;
    public:
        fps(international i)
        {
            float m = i.getm();
            float cm = i.getcm();
            in = (m*100 + cm)/2.54;
            ft = int(in/12);
            in = in - ft*12; 
        }
        void display(){
            cout<<ft<<" feet and "<<in<<" inches."<<endl;
        }
};

int main(void)
{
    float m,cm;
    cout<<"Enter meter and centimeter values: ";
    cin>>m;
    cin>>cm;
    international i = international(m,cm);
    fps f = fps(i);
    f.display();
    return 0;
}