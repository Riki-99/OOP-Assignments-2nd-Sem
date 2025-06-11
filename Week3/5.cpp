// Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.

// An employee with ... ... ... has received Rs ... ... ...as a bonus

// and

// had worked ... ... ... hours as overtime in the year ... ... ...


#include <iostream>
using namespace std;

class employee
{
    int employee_id;
    float total_bonus;
    float total_overtime;
    int year;
    // Overtime in hours
    public:

    void setpara(int id, float bonus, float overtime, int y)
    {
        employee_id = id;
        total_bonus = bonus;
        total_overtime = overtime;
        year = y;
    }

    void displayreport()
    {
        cout<<"An employee with ID: "<<employee_id<<" has received Rs. "<<total_bonus<<" as a bonus and had worked "<<total_overtime<<" hours overtime in the year "<<year<<endl;
    }
};

int main(void)
{
    // Declaring an array of objects of the class employee 
    employee employees[40];
    int num, id, yr;
    float bonus,overtime;
    cout<<"Enter number of employees: ";
    cin>>num;
    cout<<"Enter the year : ";
    cin>>yr;
    for(int i = 0; i < num; i++)
    {
        cout<<"For employee "<<i+1<<endl;
        cout<<"ID: ";
        cin>>id;
        cout<<"Total bonus: ";
        cin>>bonus;
        cout<<"Total overtime hours: ";
        cin>>overtime;
        employees[i].setpara(id,bonus,overtime, yr);
    }

    // Different loops so that output starts only when all inputs end
    for(int i = 0; i < num; i++)
    {
        employees[i].displayreport();
    }
    return 0;
}