//Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments

// -  veena, guitar, sitar, sarod and mandolin under string()

// -  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()

// -  tabla, mridangam, bangos, drums and tambour under perc()

// It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows

// Type of instruments to be displayed

// a.  String instruments

// b.  Wind instruments

// c.  Percussion instruments

// The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.

#include <iostream>
#include <string>

using namespace std;

class Musicians{
    protected:
        string *strInstruments;
        string *windInstruments;
        string *percInstruments;
    public:
        Musicians(){
            strInstruments = new string[5];
            windInstruments = new string[5];
            percInstruments = new string[5];
        }

        // Copy constructor, not required for now as per the question
        // Musicians(Musicians& m)
        // {
        //     strInstruments = new string[5];
        //     windInstruments = new string[5];
        //     percInstruments = new string[5];

        //     for(int i = 0 ; i < 5; i++)
        //     {
        //         strInstruments[i] = m.strInstruments[i];
        //         windInstruments[i] = m.windInstruments[i];
        //         percInstruments[i] = m.percInstruments[i];
        //     }

        // }

        ~Musicians(){
            delete[] strInstruments;
            delete[] windInstruments;
            delete[] percInstruments;
        }

        void String();
        void perc();
        void wind();


};

void Musicians::String(){
    strInstruments[0] = "Veena";
    strInstruments[1] = "Guitar";
    strInstruments[2] = "Sitar";
    strInstruments[3] = "Sarod";
    strInstruments[4] = "Mandolin";
}

void Musicians::wind(){
    windInstruments[0] = "Flute";
    windInstruments[1] = "Clarinet";
    windInstruments[2] = "Saxophone";
    windInstruments[3] = "Nadhaswaram";
    windInstruments[4] = "Piccolo";
}

void Musicians::perc(){
    percInstruments[0] = "Tabla";
    percInstruments[1] = "Mridangam";
    percInstruments[2] = "Bangos";
    percInstruments[3] = "Drums";
    percInstruments[4] = "Tambour";
}

class TypeIns : public Musicians{  
    public:

    TypeIns() : Musicians(){
        String();
        wind();
        perc();
    };

    void showStr(){
        cout<<endl<<"String instuments: "<<endl;
        for(int i = 0; i < 5; i++)
        {
            cout<<*(strInstruments+i)<<endl;
        }
    }

    void showWind(){
        cout<<endl<<"Wind instuments: "<<endl;
        for(int i = 0; i < 5; i++)
        {
            cout<<*(windInstruments+i)<<endl;
        }
    }

    void showPerc(){
        cout<<endl<<"Percussion instuments: "<<endl;
        for(int i = 0; i < 5; i++)
        {
            cout<<*(percInstruments+i)<<endl;
        }
    }

    void get(){
        showStr();
        showWind();
        showPerc();
    }

    void show(){
        int opt = 1;
        cout<<endl<<"Which instruments do you want to see?"<<endl;
        cout<<"1. String"<<endl;
        cout<<"2. Wind"<<endl;
        cout<<"3. Percussion"<<endl;
        cin>>opt;
        switch(opt)
        {
            case 1:
                showStr();
                break;
            case 2:
                showWind();
                break;
            case 3: 
                showPerc();
        }
    }
};

int main(void)
{
    TypeIns t;
    t.get();
    t.show();
}