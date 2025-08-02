#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct student{
    char name[30], dept[30], addr[30];
    int id;
    student(){}
    student(const char*n, int i, const char*dpt, const char*adr) : id(i){
        strcpy(name, n);
        strcpy(dept, dpt);
        strcpy(addr, adr);
    }
};

int main(void)
{
    fstream file;
    file.open("4.txt", ios::in | ios::out | ios::binary);
    student* s[10];
    student s1 = student("Rikison", 1, "Computer", "Thankot");
    student s2 = student("Prasam", 2, "Computer", "Sakhu");
    s[0] = &s1;
    s[1] = &s2;

    for(int i = 0; i<2; i++)
    {
        file.write(reinterpret_cast<char*>(s[i]), sizeof(student));
    }

    file.seekg(0);

    // Reading
    for(int i = 0; i<2; i++)
    {
        // dy
        student *s = new student();
        file.read(reinterpret_cast<char*>(s), sizeof(student));
        cout<<(i+1)<<" "<<s->name<<" "<<s->id<<" "<<s->dept<<" "<<s->addr<<endl;
        delete s;
    }
    return 0;
}

