#include <iostream>
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
    return ostr<<c.real<<" + "<<c.imag<<"i"<<endl;
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