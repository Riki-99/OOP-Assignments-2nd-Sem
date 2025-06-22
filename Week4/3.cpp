//Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.
#include <iostream>

using namespace std;

class dept{
    private:
        int id;
        string name;
        static int ct;

    public:
        dept(){
            id = 12;
            name = "Computer";
            ct++;
            cout<<"Constructor " << ct << " called in." <<endl;
        }

        dept(int id_ipt, string name_ipt){
            id = id_ipt;
            name = name_ipt;
            ct++;
            cout<<"Constructor " << ct << " called in." << endl;
        }

        ~dept(){
            cout<<"Object " << ct << " goes out of scope." << endl;
        }

};

int dept::ct = 0;

int main(void)
{
    {
        dept d1;
    }
    dept d2(12, "Electronics");
    return 0;
}