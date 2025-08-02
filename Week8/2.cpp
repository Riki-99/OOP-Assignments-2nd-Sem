#include <iostream>
using namespace std;

// A class for wrapping all three modifying stuff into one unit
class wrapperFormat{
    public:
    int width, prec, fill;
    wrapperFormat(int w, int p, int f): width(w), prec(p), fill(f){}
};
// Overloading the insertion operator which return the ostream 
ostream& operator << (ostream& obj, wrapperFormat& wf)
{
    // Width fill and precision are the member function of the class ostream
    obj.width(wf.width);
    obj.fill(wf.fill);
    obj.precision(wf.prec);
    return obj;
}


int main(void)
{
    wrapperFormat wformat(20, 3, '*');
    cout<<wformat<<"Hello I am Rikison"<<endl;
    return 0;
}