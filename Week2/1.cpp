//Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function

#include <iostream>
using namespace std;

typedef struct{
    int mm;
    int dd;
    int yy;
} date;

int main(void)
{
    date today;
    cout<<"Enter year: ";
    cin>>today.yy;
    cout<<"Enter month: ";
    cin>>today.mm;
    cout<<"Enter day: ";
    cin>>today.dd;
    cout<<today.mm << "/" << today.dd << "/" << today.yy << endl;
    return 0;
}

