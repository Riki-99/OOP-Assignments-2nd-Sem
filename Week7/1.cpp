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
        virtual ~shape(){
            cout<<"Shape destroyed"<<endl;
        }
        virtual void Area(){
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
         void Area(){
            float r;
            cout<<"Enter radius : ";
            cin>>r;
            area = pi * r * r;
        }

          void display(){
            Area();
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
         void Area(){
            float l,b;
            cout<<"Enter length and breadth : ";
            cin>>l;
            cin>>b;
            area = l * b;
        }

          void display(){
            Area();
            cout<<"Overridden by rectangle"<<endl;
            shape::display();
          }
        ~rectangle(){
            cout<<"Rectangle destroyed"<<endl;
        }
};

class trapezoid : public shape{
    public:
         void Area(){
            cout<<"Overridden trapezoid"<<endl;
            shape::Area();
        }

          void display(){
            Area();
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
    return 0;
}