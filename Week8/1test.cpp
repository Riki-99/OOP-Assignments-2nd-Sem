#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class entry{
    char name[30];
    float price;
    int quantity;
    float total;
    public:
        entry(){}
        entry(char s[], float p, int q) :  price(p), quantity(q)
        {
            total = p*q;
            strcpy(name, s);
        }
        entry(entry &e)
        {
            strcpy(name,e.name);
            price = e.price;
            quantity = e.quantity;
            total = e.total;
        }
        void display(){
            cout<<setw(15)<<name<<setw(7)<<price<<setw(3)<<quantity<<setw(8)<<total<<endl;
        }

        float getTotal(){
            return total;
        }
};

class record{
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
    char s1[] = "Momo";
    char s2[] = "Pencil";
    char s3[] = "Apples";
    entry e1(s1, 120, 2);
    entry e2(s2, 20, 5);
    entry e3(s3, 100, 4);
    entry e[3] = {e1, e2, e3};
    entry etest[3];
    streamobj.open("1.txt", ios::in | ios::out | ios::binary);
    for(int i = 0; i<3; i++)
    {
        streamobj.write(reinterpret_cast<char *>(&e[i]), sizeof(e[i]));
    }
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