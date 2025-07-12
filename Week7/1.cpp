#include <iostream>
using namespace std;
const double pi = 3.141592654;

class shape{
    protected:
        string name;
        float area;
    public:
        // Pure virtual functions
        shape(){
            name = "Trapezoid";
        }
        ~shape(){
            cout<<"Shape destroyed"<<endl;
        }
        virtual void calcArea(){
            float a,b,h;
            cout<<"Enter values of a, b and h";
            cin>>a;
            cin>>b;
            cin>>h;
            area =  0.5 * (a+b) * h;
        }
        virtual void display()
        {
            cout<<"Name : " << name <<endl;
            cout<<"Area : " << area <<endl;
        }
};

class circle : public shape{
    public:
        circle(){
            name = "Circle";
        }
         void calcArea(){
            float r;
            cout<<"Enter radius : ";
            cin>>r;
            area = pi * r * r;
        }

          void display(){
            calcArea();
            cout<<"Overridden by circle"<<endl;
            shape::display();
          }
        ~circle(){
            cout<<"Circle destroyed"<<endl;
        }
};

class rectangle : public shape{
    public:
        rectangle(){
            name = "Rectangle";
        }
         void calcArea(){
            float l,b;
            cout<<"Enter length and breadth : ";
            cin>>l;
            cin>>b;
            area = l * b;
        }

          void display(){
            calcArea();
            cout<<"Overridden by rectangle"<<endl;
            shape::display();
          }
        ~rectangle(){
            cout<<"Rectangle destroyed"<<endl;
        }
};

class trapezoid : public shape{
    public:
         void calcArea(){
            cout<<"Overridden trapezoid"<<endl;
            shape::calcArea();
        }

          void display(){
            calcArea();
            cout<<"Overridden"<<endl;
            shape::display();
          }
        ~trapezoid(){
            cout<<"Trapezoid destroyed"<<endl;
        }
};

int main(void)
{
    circle c;
    rectangle r;
    trapezoid t;
    shape* s[3];
    s[0] = &c, s[1] = &r, s[2] = &t; 

    s[0]->display();
    s[1]->display();
    s[2]->display();
}