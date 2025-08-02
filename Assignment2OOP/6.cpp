// f) Conversion from the pound/ounce to Kg/gm


#include <iostream>
using namespace std;

class international{
    private:
        float kg, gm;
    public:
        international(float k,float g) : kg(k), gm(g){}
        void display(){
            cout<<kg<<" kg and "<<gm<<" grams. "<<endl;
        }
};

class fps{
    private:
        float pound, ounce;
    public:
        fps(float p, float o) : pound(p), ounce(o){}
        operator international(){
            float g = pound*453.6 + ounce * 28.35;
            float kg = int(g/1000);
            g = g - kg*1000;
            return international(kg, g);
        }
};

int main(void)
{
    float p,o;
    cout<<"Enter pounds and ounces: ";
    cin>>p;
    cin>>o;
    fps f(p,o);
    international i = international(f);
    i.display();
    return 0;
}