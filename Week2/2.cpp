//Write a program using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments. Use pass by reference in any one of the function above.

#include <iostream>

using namespace std;

int feetToInches()
{
    int ft;
    cout<<"Enter feet: ";
    cin>>ft;
    cout<<"Equivalent inches: " << ft*l12;
}

void feetToInches(int &ft)
{
    ft = ft*12;
}

int feetToInches(int ft, int inches)
{
    return ft * 12 + inches;
}

int main(void)
{
    int ft, inches;
    cout<<"Feet: ";
    cin>>ft;
    cout<<"Inches: ";
    cin>>inches;

    int totalinches = feetToInches(ft, inches);
    cout<<"Total inches: "<<totalinches<<endl;

    feetToInches(ft);
    cout<<"Total inches: "<<ft<<endl;

    feetToInches();
    return 0;
}
