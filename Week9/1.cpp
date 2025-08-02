#include <iostream>
using namespace std;

template <class T>

class summer{
    public:
        T add(T* tptr, int len)
        {
            T sum = 0;
            for(int i = 0; i < len; i++)
            {
                sum+= *(tptr+i);
            }
            return sum;
        }   
};

int main(void)
{
    int ints[] = {1,2,3,4,5};
    float floats[] = {1.4,2.9,3.8,4.6,5.3};
    summer <int> intsummer;
    summer <float> floatsummer;
    int intsum = intsummer.add(ints, 5);
    float floatsum = floatsummer.add(floats, 5);
    cout<<"Sum of int array: "<<intsum<<endl;
    cout<<"Sum of float array: "<<floatsum;
    return 0;
}