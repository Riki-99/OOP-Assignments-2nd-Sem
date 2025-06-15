//Write a program that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages respectively in year 2010. Let us assume that the salaries in year 2009 are

//Chief executive officer Rs. 35000/m

//Information officer Rs. 25000/m

//System analyst Rs. 24000/m

//Programmer Rs. 18000/m

Make a function that takes two arguments; one salary and the other increment. Use proper default argument.

#include <iostream>
using namespace std;

int modifiedSalary(int salary = 10000, int increment = 9)
{
    return salary + increment*salary/100;
}

int main(void)
{
    int ceoSalary = 35000;
    int ioSalary = 25000;
    int saSalary = 24000;
    int programmerSalary = 18000;
    cout<<"CEO's salary: "<<modifiedSalary(ceoSalary, 9)<<endl;
    cout<<"IO's salary: "<<modifiedSalary(ioSalary, 9)<<endl;
    cout<<"System Analyst's salary: "<<modifiedSalary(saSalary, 9)<<endl;
    cout<<"Programmer's salary: "<<modifiedSalary(programmerSalary, 9)<<endl;
    return 0;
}
