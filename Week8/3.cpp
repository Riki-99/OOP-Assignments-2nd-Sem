#include <iostream>
#include <cmath>
using namespace std;

class complex{
    private:
        float real, imag;
    public:
    // complex(){}
    // complex(float r, float i): real(r), imag(i){}
    friend ostream& operator << (ostream& ostr, complex &c);
    friend istream& operator >> (istream& istr, complex &c);

};

ostream& operator << (ostream& ostr, complex &c){
    string sign = (c.imag<0)?" - ":" + ";
    return ostr<<c.real<<sign<<"i"<<abs(c.imag);
};

istream& operator >> (istream& istr, complex &c)
{
    istr>>c.real>>c.imag;
    return istr;
};

int main(void)
{
    complex c;
    cout<<"Enter real part and imaginary part of complex number : ";
    cin>>c;
    cout<<"The complex number is : "<<c;
    return 0;
}