#include <iostream>
#include <fstream>
using namespace std;

/*The useful classes for wokring with files are obtained from fstream : 
1. fstreambase
2. ifstream --> derived from fstreambase
3. ofstream -- derived from fstreambase

In order to work with files in C++, you will have to open it. 
There are primarily 2 ways to open a file:

1. Using the constructor
2. Using the member function open of the class (the above classes)


*/

int main(void)
{
    // OPening files using consturctor.
    string st = "Rikison dada";
    ofstream out("gg.txt");
    out<<st;
    return 0;
}