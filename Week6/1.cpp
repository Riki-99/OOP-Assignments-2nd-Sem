//Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.

#include <iostream>
using namespace std;

class Distance{
    private:
        float meter, centimeter;
    public:
        operator float()
        {
            return meter + centimeter*0.01;
        }

        Distance(float m) : meter(int(m)), centimeter((m - int(m)) * 100){}
        Distance (float m, float cm) : meter(m), centimeter(cm) {}

        void display(){
            cout<<meter<<" meter "<< centimeter << " centimeter "<<endl;
        }
};

int main(void)
{
    Distance d1(1.71);
    d1.display();

    float d = (float) Distance(1,50);
    cout<<"Float value : "<<d << " meters" <<endl;
    return 0;
}