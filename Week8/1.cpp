//Write a program to demonstrate the use of different ios flags and functions to format the output. Create a program to generate the bill invoice of a department store by using different formatting.


#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Class for each entry
class entry{
    char name[30];
    float price;
    int quantity;
    float total;
    public:
        entry(){}
        // Since I'm using string literals, C forbids me from changing them and I will comply with it
        // so I use const char [] instead of just char[]
        entry(const char s[], float p, int q) :  price(p), quantity(q)
        {
            total = p*q;
            strcpy(name, s);
        }
        // A copy constructor to allow copying in the "records" class
        entry(entry &e)
        {
            strcpy(name,e.name);
            price = e.price;
            quantity = e.quantity;
            total = e.total;
        }
        void display(){
            cout<<setw(15)<<uppercase<<name<<" "<<setw(7)<<setprecision(2)<<fixed<<price<< " "<<setw(3)<<quantity<< " " <<setw(8)<<total<<endl;
        }

        float getTotal(){
            return total;
        }
};

// A class that builds up on the entry class to keep records
class record{
    // Maximum 10 entires for now, dynamic memory allocation is a hassle
    entry entries[10];
    int length;
    public:
        record(entry *e, int l) : length(l){
            for(int i = 0; i < l; i++)
            {
                entries[i] = *(e+i);
            }

        }
        void display(){
            float total = 0;
            for(int i = 0; i<length; i++)
            {
                entries[i].display();
                total+=entries[i].getTotal();
            }
            cout<<setw(30)<<"Total :"<<total<<endl;
        }
};





int main(void)
{
    fstream streamobj;
    entry e1("Momo", 120.321, 2);
    entry e2("Pencil", 20.543, 5);
    entry e3("Apples", 100.283, 4);
    entry e[3] = {e1, e2, e3};
    entry etest[3];
    streamobj.open("1.txt", ios::in | ios::out | ios::binary);
    for(int i = 0; i<3; i++)
    {
        // For some reason, the addresses need to be casted to char* to use read/write using streamobj
        streamobj.write(reinterpret_cast<char *>(&e[i]), sizeof(e[i]));
    }
    // The get pointer points to the start of the file (at index zero)
    streamobj.seekg(0);
    for(int i = 0; i<3; i++)
    {
        streamobj.read(reinterpret_cast<char *>(&etest[i]), sizeof(etest[i]));
    }
    record r(etest, 3);
    r.display();
    streamobj.close();
    return 0;
}