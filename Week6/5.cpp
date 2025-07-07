//Write a base class that asks the user to enter a complex number, and make a derived class that adds the complex number of its own to the base. Finally, make a third class that is a friend of derived and calculate the difference between the base complex number and its own complex number.


#include <iostream>
using namespace std;

class comp1{
    protected:
      float real, imag;
    public:
    comp1(float r, float i) : real(r), imag(i){}
    // Getter functions to help children class access this class's members
    float getReal(){return real;}
    float getImag(){return imag;}
    void display(){
        cout<<real << " + " << imag<< "i"<<endl;
    }
};

class comp2;

class comp2friend{
    public:
        comp1 diff(comp1 c1, comp2 c2);
    };
    
class comp2 : public comp1
    {
        public:
        comp2(float r, float i) : comp1(r,i){}
        comp1 add(comp1 c)
        {
            // A child cannot access the properties of it's parent class in a different instance
            return comp1(real + c.getReal(), imag + c.getImag());
        }
        friend comp2friend;
    };

comp1 comp2friend::diff(comp1 c1, comp2 c2)
        {
            // A friend class can access property of it's friend but not of the friend's parent
            return comp1(c1.getReal() - c2.real, c1.getImag() - c2.imag);
        }

int main (void){
    float real, imag;
    cout<<"Enter real part: ";
    cin>>real;
    cout<<"Enter imaginary part : ";
    cin>>imag;
    comp1 c1(real,imag);
    comp2 c2(3,4);
    comp2friend c3;
    c1 = c2.add(c1);
    c1.display();
    c1 = c3.diff(c1, c2);
    c1.display();
    return 0;
}

