#include <iostream>
using namespace std;

template <class T>

class queue{
    T values[3];
    int latest;
    public:
    queue(){
        latest = 0;
    }
    void insert(T val){
        if(latest>=3)
        {
            throw 4;
        }
        values[latest++] = val;
    }

    void remove()
    {
        if(latest <= 0)
        {
            throw -1;
        }
        for(int i = 0; i<latest; i++)
        {
            values[i] = values[i+1];
        }
        latest--;
    }

    void display(){
        for(int i = 0; i < latest; i++)
        {
            cout<<values[i]<<" ";
        }
        cout<<endl;
    }
};

int main(void)
{
    queue <int> intqueue;
    try{
        intqueue.remove();
    }
    catch(int err)
    {
        if(err == -1)
        cout<<"Error: No elements to remove."<<endl;
    }
    intqueue.insert(1);
    intqueue.insert(2);
    intqueue.insert(3);
    try{
        intqueue.insert(4);
    }
    catch(int code)
    {
        if(code == 4)
        cout<<"Error: maximum queue size exceeded;"<<endl;
    }
    intqueue.display();
    intqueue.remove();
    intqueue.display();

    return 0;
}