#include <iostream>
#include <cmath>

using namespace std;
const double pi = 3.141592654;

// A super class shape that contains basic template for its children shapes
class shape
{
    // protected access specifier lets children access these unlike private
    protected:
    float sides[3];
    float perimeter = 0;
    float area;
    
    public:
    int sideCount;
    int uniqueSideCount;

    // virtual keyword so that we can ovveride this function later on, mostly necessary because
    // circle is much different than other two shapes.
    virtual void inputDetails()
    {
        for(int i = 0 ; i < uniqueSideCount; i++)
        {
            cout<<"Side "<<i+1<<": ";
            cin>>sides[i];
        }
    }

    virtual void calculatePerimeter()
    {
        for(int i = 0; i<uniqueSideCount; i++)
            perimeter += sides[i];
        perimeter*= sideCount/uniqueSideCount;
    }

    virtual void calculateArea(){
        float s = (sides[0] + sides[1] + sides[2])/2;
        cout<<s;
        area = sqrt(s*(s-sides[0])* (s-sides[1])* (s - sides[2]));
    }

    virtual void displayDetails()
    {
        calculateArea();
        calculatePerimeter();
        cout<<endl<<"Sides: "<<sideCount<<endl;
        cout<<"Perimeter: "<<perimeter<<endl;
        cout<<"Area: "<<area<<endl;
    }

};

//Inheriting shape's properties for children classes
class triangle : public shape{
    public:
    triangle(){
        sideCount = 3;
        uniqueSideCount= 3;
    }
};

class square : public shape{
    public:
    square(){
        sideCount = 4;
        uniqueSideCount= 1;
    }

    void calculateArea() override{
        area = sides[0] * sides[0];
    }
};

// Requires the most customizations as it is the most unique of the shapes
class circle : public shape{
    public:
    circle(){
        // Technically side count is infinity but, we make do with 1 since
        // 1 is much easier to deal with than infinity
        sideCount = 1;
        uniqueSideCount= 1;
    }

    void calculateArea() override{
        area = pi * sides[0] * sides[0];
    }

    void calculatePerimeter() override{
        perimeter = 2 * pi * sides[0];
    }

    void inputDetails() override{
        cout<<"Enter radius: ";
        cin>>sides[0];
    }

    void displayDetails() override{
        calculateArea();
        calculatePerimeter();
        cout<<endl<<"Perimeter: "<<perimeter<<endl;
        cout<<"Area: "<<area<<endl;
    }
};

int main(void)
{
    triangle t;
    circle c;
    square s;
    cout<<"Choose one: "<<endl<<"1. Triangle"<<endl<<"2. Square"<<endl<<"3. Circle"<<endl<<endl;
    int opt;
    cin>>opt;
    switch(opt){
        case 1:
            t.inputDetails();
            t.displayDetails();
            break;
        case 2:
            s.inputDetails();
            s.displayDetails();
            break;
        case 3:
            c.inputDetails();
            c.displayDetails();
            break;
        default:
            cout<<"Invalid.";
    }
    return 0;
}