//Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).

#include <iostream>

using namespace std;

class threeD{
    private:
        float x,y,z;
    public:
        threeD(float x, float y, float z) : x(x), y(y), z(z){}
        threeD() : x(0), y(0), z(0){}
        void display()
        {
            cout<<"(" <<x << ", " << y << ", " << z <<")"<<endl;
        }
        friend threeD operator +(threeD, threeD);
        friend threeD operator -(threeD, threeD);
};

threeD operator +(threeD t1, threeD t2){
    return threeD (t1.x + t2.x, t1.y + t2.y, t1.z + t2.z);
}

threeD operator -(threeD t1, threeD t2)
{
    t2.x*=-1;  
    t2.y*=-1;
    t2.z*=-1;
    return t1 + t2;
}

int main(void)
{
    threeD c1(1,5,2);
    threeD c2(10,5,6);
    threeD c3 = c1 + c2;
    threeD c4 = c3-c1;
    c3.display();
    c4.display();
    return 0;
}