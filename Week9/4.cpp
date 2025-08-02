#include <iostream>
using namespace std;

class errorTest{
    public:
        void tester(int x){
            if(x == 1)
            {
                throw 1;
            }
            else if(x == 2)
            {
                throw 'c';
            }
            else{
                throw 3.14;
            }
        }
};

int main(void)
{
    errorTest t;
    try{
        try{
            t.tester(1);
        }
        catch(int x)
        {
            cout<<"x is 1"<<endl;
            throw;
        }
        catch(char c)
        {
            cout<<"x is 2";
        }
        catch(float f)
        {
            cout<<"x is neither 1 nor 2";
        }
    }
    catch(int y){
        cout<<"Caught rethrown exception, x = 1";
    }
    return 0;
}