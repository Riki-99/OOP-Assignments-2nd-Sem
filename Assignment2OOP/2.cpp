//b) Conversion from Cartesian coordinate to the polar coordinate system.


#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.141592653;

class polar{
    private:
        float r;
        float theta;
    public:
        polar(float r, float t) : r(r), theta(t){}
        void display(){
            cout<<"(r, 0)  = ("<< r<<", "<<theta<<")";
        }

};

class cartesian{
    private:
        float x,y;
    public:
    operator polar(){
        float r = sqrt(x*x + y*y);
        float th = atan(y/x);
        th = th * 180/PI;
        return polar(r, th);
    }
    void ipt(){
        cin>>x;
        cin>>y;
    }   
};

int main(void)
{
    cartesian c;
    cout<<"Enter x and y coords: ";
    c.ipt();
    polar p = polar(c);
    p.display();
    return 0;
}