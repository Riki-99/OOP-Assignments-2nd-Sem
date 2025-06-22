// Write a program that illustrates the following relationship and comment on them. 

// i) const_object.non_const_mem_function

// ii) const_object.const_mem_function

// iii) non_const_object.non_const_mem_function

// iv) non_const_object.const_mem_function

#include <iostream>

using namespace std;

class person{
    private:
        int id;
        int age;
    public:
    person(int idipt, int ageipt) : id(idipt), age(ageipt){}
    
    void birthday(){
        age++;
    }

    void display() const{
        cout<<"Id : "<<id<<endl<<"Age : "<<age<<endl;
    }
};

int main(void)
{
    person p1(1,18);
    const person p2(2, 40);
    
    //Const obj. non const member function
    // p2.birthday();  Cannot be called because the birthday function tries to change the value

    //Const obj. const member function
    p2.display(); //Works fine

    //Non const obj. const member function
    p1.display();

    //Non const obj. non const member function
    p1.birthday();
    p1.display();
    return 0;
}