// d) Conversion from the 24-hour clock to 12 hour


#include <iostream>
using namespace std;

class time12{
    protected:
        int hh, mm, ss;
    public:
    time12(int h, int m, int s) : hh(h), mm(m), ss(s){}
    void display(){
        cout<<((hh<10)?"0":"")<<hh<<" : "<<((mm<10)?"0":"")<<mm<<" : "<<((ss<10)?"0":"")<<ss<<endl;
    }
};

class time24{
    private:
    int hh, mm, ss;
    public:
        time24(int h, int m, int s) : hh(h), mm(m), ss(s){}
        operator time12(){
            int h;
            if(hh<=12)
            {
                h = hh;
            }
            else
            {
                h = hh-12;
            }
            return time12(h,mm,ss);
        }
};

int main(void)
{
    int h,m,s;
    cout<<"Enter hh, mm and ss in 24 hr format: ";
    cin>>h;
    cin>>m;
    cin>>s;
    time24 t24(h,m,s);
    time12 t12 = time12(t24);
    t12.display();
    return 0;
}