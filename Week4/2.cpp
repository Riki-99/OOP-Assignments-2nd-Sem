//Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.

#include <iostream>
#include <cstring>

using namespace std;

class dynamic{
    private:
        char* arr;
    
    public:
        dynamic(){
            arr = new char[40];
            strcpy(arr,"Engineers are");
        }

        dynamic(int x)
        {
            arr = new char[40];
            strcpy(arr, " Creatures of logic.");
        }

        ~dynamic()
        {
            delete[] arr;
        }

        // Use by reference so that new constructor is not called in.
        void join(dynamic &c1, dynamic &ch)
        {
            char *c = ch.arr;
            char *cdest = c1.arr;
            char* output = new char[80];
            int len = 0, i = 0;
            while(cdest[len] != '\0')
                {
                    output[len] = cdest[len];
                    len++;
                }
            while(c[i] != '\0')
            {
                output[len] = c[i];
                i++;
                len++;
            }
            cout<<output;
            delete[] output;
        }
};


int main(void)
{
    dynamic str1;
    dynamic str2(0);
    str1.join(str1, str2);
    return 0;
}