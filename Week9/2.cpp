#include <iostream>
using namespace std;

template <class T>

class queue{
    T values[10];
    int latest;
    public:
    queue(){
        latest = 0;
    }
    void insert(T val){
        values[latest++] = val;
    }

    void remove()
    {
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
    intqueue.insert(1);
    intqueue.insert(2);
    intqueue.insert(3);
    intqueue.display();
    intqueue.remove();
    intqueue.display();

    queue <float> floatqueue;
    floatqueue.insert(1.3);
    floatqueue.insert(2.5);
    floatqueue.display();
    floatqueue.remove();
    floatqueue.display();

    return 0;
}