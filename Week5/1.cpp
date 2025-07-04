//Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

// A. Make a particular member function of one class as a friend function of another class for addition.

// B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.

// C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.

// Make least possible classes to demonstrate all the above in a single program without conflict.

#include <iostream>
using namespace std;

class twoD;
class vector2d;

class addition{
    public:
        twoD operate(twoD c1, vector2d v1);
};

class operations{
    public:
        twoD diff(twoD c1, vector2d);
        twoD mul(twoD c, vector2d);
        twoD divide(twoD c, vector2d);
        void display(twoD);
};

class twoD{
    private:
        float x;
        float y;
    public: 
    twoD(float x1, float y1) : x(x1), y(y1){};
    friend twoD addition::operate(twoD, vector2d);
    friend operations;
};

class vector2d{
	private:
		float x;
		float y;
	public:
		vector2d(float x1, float y1) : x(x1), y(y1){};
		friend twoD addition::operate(twoD, vector2d);
		friend operations;	
};

twoD addition::operate(twoD c, vector2d v)
{
            return twoD (c.x + v.x, c.y + v.y);
}

twoD operations::diff(twoD c, vector2d v)
{
    return twoD (c.x - v.x, c.y - v.y);
}

twoD operations::mul(twoD c, vector2d v)
{
    return twoD (v.x*c.x, v.y*c.y);
}

twoD operations::divide(twoD c, vector2d v)
{
    return twoD (c.x/v.y, c.y/v.y);
}

void operations::display(twoD c)
{
    cout<<"("<<c.x<<", "<<c.y<<")"<<endl;
}


int main(void)
{
    twoD c1(1,2);
    vector2d v1(3,4);
    addition a;
    operations o;

    cout<<"c1 + v1 : ";
    o.display(a.operate(c1,v1));

    cout<<"c1 - v1 : ";
    o.display(o.diff(c1,v1));

    cout<<"c1 * v1 : ";
    o.display(o.mul(c1,v1));

    cout<<"c2 / v2 : ";
    o.display(o.divide(c1,v1));
    return 0;
}
