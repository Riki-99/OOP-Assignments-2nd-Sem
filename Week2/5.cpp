//Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.

#include <iostream>

using namespace std;

inline int netSal(int totalSalary)
{
    return 0.9* totalSalary;
}

int main(void)
{
    int sal;
    cout<<"Enter the salary of employee: ";
    cin>>sal;
    cout<<"Net salary after tax is : "<<netSal(sal)<<endl;
    return 0;
}
