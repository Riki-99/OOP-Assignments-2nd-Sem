#include <iostream>
using namespace std;

class Integer
{
    int val;
    public:
    int isPrime()
    {
        int c = 0;
        if(val == 1)
            return 2;
        for(int i = 2; i <= val/2; i++)
        {
            if(val%i == 0)
                return 0;
        }
        return 1;
    }

    void inputVal()
    {
        cin>>val;
    }
};

int main(void)
{
    char opt = 'y';
    Integer num;
    while(opt == 'y'){
        cout<<"Enter a number: ";
        num.inputVal();
        if(num.isPrime() == 2)
            cout<<"Neither prime nor composite"<<endl;
        else
            cout<<"It is: "<<((num.isPrime())? "prime":"composite")<<endl;
        cout<<"Do you want to continue checking? (y/n)";
        cin>>opt;
    }
    return 0;
}