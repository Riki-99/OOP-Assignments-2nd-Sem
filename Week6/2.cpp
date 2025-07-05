//Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.
#include <iostream>
using namespace std;

class freedom;

class imperial{
    private:
        float m, cm;
    public:
        imperial(float m , float cm) : m(m), cm(cm){}
        operator freedom();

        void display(){
            cout<<m<<" meter "<<cm<<" centimeter"<<endl;
        }
};

class freedom{
    private:
        float feet, inch;
    public:
        freedom(float f, float i) : feet(f), inch(i){}
        operator imperial(){
            float totInch = feet * 12 + inch;
            float cm = totInch * 2.54;
            float m = int(cm/100);
            cm = cm - m * 100;
            return imperial(m, cm);
        }

        void display(){
            cout<<feet << " feet " << inch << " inches"<<endl;
        }
};

imperial::operator freedom(){
      float cmTot = m * 100 + cm;
            float in = cmTot/2.54;
            float ft =   int(in/12);
            in = in - ft * 12;
            return freedom(ft, in);
}

int main(void)
{
    float ft, in;
    cout<<"Enter float, inches : "<<endl;
    cin>>ft;
    cin>>in;
    freedom f1(ft, in);
    cout<<"Eqv imperial value : "<<endl;
    ((imperial)f1).display();

    float cm, m;
    cout<<"Enter meters, centimeters : "<<endl;
    cin>>m;
    cin>>cm;
    imperial i1(m, cm);
    cout<<"Eqv freedom value : "<<endl;
    ((freedom)i1).display();

    return 0;
}