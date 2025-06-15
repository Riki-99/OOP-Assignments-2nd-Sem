//Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.
#include <iostream>

using namespace std;

int& setHigher(int &tmp1, int &tmp2)
{
    return (tmp1 > tmp2)? tmp1: tmp2;
}

int main(void)
{
    int t1, t2, tnew;
    cout<<"Enter temp1: ";
    cin>>t1;
    cout<<"Enter temp2: ";
    cin>>t2;
    cout<<"Enter new higher temperature: ";
    cin>>tnew;
    setHigher(t1,t2) = tnew;
    cout<<"T1 : " << t1 << " T2 : " << t2;
    return 0;
}
