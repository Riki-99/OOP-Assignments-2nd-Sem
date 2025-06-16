//Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value and make conversion functions in each class for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.

#include <iostream>
using namespace std;

class Celsius{
    private:
    float value;
    public:
    float toFahrenheit(float c)
        {
            return 9*c/5 + 32;
        }
    void input()
    {
        cin>>value;
    }
    float val(){
        return value;
    }
};

class Fahrenheit{
    private:
    float value;
    public:
    float toCelsius(float f)
        {
            return (f-32) * 5/9;
        }
        void input()
    {
        cin>>value;
    }
    float val(){
        return value;
    }
};

int main(void)
{
    Celsius cel;
    Fahrenheit fah;
    cout<<"Enter Fahrenheit value: ";
    fah.input();
    cout<<"Celsius equivalent is : " <<fah.toCelsius(fah.val())<<endl;
    cout<<"Enter Celsius value: ";
    cel.input();
    cout<<"Fahrenheit equivalent is : "<<cel.toFahrenheit(cel.val())<<endl;
    return 0;
}