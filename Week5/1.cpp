#include <iostream>
using namespace std;

class twoD;

class addition{
    public:
        twoD operate(twoD c1, twoD c2);
};

class operations{
    public:
        twoD diff(twoD c1, twoD c2);
        twoD mul(twoD c, int factor);
        twoD divide(twoD c, float factor);;
        void display(twoD);
};

class twoD{
    private:
        float x;
        float y;
    public: 
    twoD(float x1, float y1) : x(x1), y(y1){};
    friend twoD addition::operate(twoD, twoD);
    friend operations;
};

twoD addition::operate(twoD c1, twoD c2)
{
            return twoD (c1.x + c2.x, c1.y + c2.y);
}

twoD operations::diff(twoD c1, twoD c2)
{
    return twoD (c1.x - c2.x, c1.y - c2.y);
}

twoD operations::mul(twoD c, int f)
{
    return twoD (f*c.x, f*c.y);
}

twoD operations::divide(twoD c, float f)
{
    return twoD (c.x/f, c.y/f);
}

void operations::display(twoD c)
{
    cout<<"("<<c.x<<", "<<c.y<<")"<<endl;
}


int main(void)
{
    twoD c1(1,2);
    twoD c2(3,4);
    addition a;
    operations o;

    cout<<"c1 + c2 : ";
    o.display(a.operate(c1,c2));

    cout<<"c1 - c2 : ";
    o.display(o.diff(c1,c2));

    cout<<"c1 * 3 : ";
    o.display(o.mul(c1,3));

    cout<<"c2 / 2 : ";
    o.display(o.divide(c2,3.0));

}