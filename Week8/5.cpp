#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Account{
    private:
        int acc_num;
        char last_name[30];
        char first_name[30];
        long int balance;
        bool deleted;
    public:
        Account(int a, char* l, char* f, long int b): acc_num(a), balance(b)
        {
            strcpy(last_name, l);
            strcpy(first_name, f);
            deleted = false;
        }

        Account(Account& a)
        {
            acc_num = a.acc_num;
            strcpy(last_name, a.last_name);
            strcpy(first_name, a.first_name);
            balance = a.balance;
            deleted = a.deleted;
        }

        Account(){}

        void input(int latestIndex){
                cout<<"First name: ";
                cin>>first_name;
                cout<<"Last name: ";
                cin>>last_name;
                cout<<"Balance : ";
                cin>>balance;
                acc_num = ++latestIndex;
                cout<<"Your account number is : "<<latestIndex<<endl;
        }

        void display(){
            if(deleted)
            {
                cout<<"Record already deleted.";
                return;
            }
            cout<<"Account number : "<<acc_num<<endl;
            cout<<"First name : "<<first_name<<endl;
            cout<<"Last name : "<<last_name<<endl;
            cout<<"Total balance : "<<balance<<endl;
        }

        void Delete(){
            deleted = true;
        }

        bool Deleted(){
            return deleted;
        }

        int getacc_num(){
            return acc_num;
        }
};

int main(void)
{
    fstream file;
    file.open("5.txt", ios::in | ios::out | ios::binary);
    if(!file)
    {
        ofstream newfile("5.txt", ios::binary);
        newfile.close();
        file.open("5.txt", ios::in | ios::out | ios::binary);
    }
    Account *a, *b;
    int accnum;
    //file.tellg() is of type streampos() and returns the 
    file.seekg(0, ios::end);

    int record_number = (file.tellg() > 0)?file.tellg()/sizeof(Account): 0;
    char fn[30], ln[30];
    long int blc;
    int choice = 0;
    char ch = 'Y';
    do
    {
        file.seekp(0);
        cout<<"What operation do you want to perform? "<<endl;
        cout<<"1. Add"<<endl<<"2. Update"<<endl<<"3. Delete"<<endl<<"4. Display"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                a = new Account();
                a->input(record_number);
                file.seekp(0, ios::end);
                file.write(reinterpret_cast<char*>(a), sizeof(Account));
                record_number++;
                delete a;
                file.clear();
                break;
            case 2:
                cout<<"Enter account number of details to update: ";
                cin>>accnum;
                cout<<"Enter the new details : (firstname, lastname and balance)"<<endl;
                cin>>fn;
                cin>>ln;
                cin>>blc;
                a = new Account(accnum, ln, fn, blc);
                b = new Account();
                file.seekg(sizeof(Account) * accnum-1);
                file.read(reinterpret_cast<char*>(b), sizeof(Account));
                file.clear();
                a->display();
                if(b->Deleted())
                    {
                        cout<<"Error: deleted record";
                        break;
                    }
                file.seekp(sizeof(Account) * (accnum-1));
                file.write(reinterpret_cast<char*>(a), sizeof(Account));
                delete a;
                file.clear();
                break;
            case 3:
                cout<<"Enter account number of details to delete: ";
                cin>>accnum;
                a = new Account();
                a->Delete();
                file.seekp(sizeof(Account)*(accnum-1));
                file.write(reinterpret_cast<char*>(a), sizeof(Account));
                file.clear();
                cout<<"Successfully deleted."<<endl;
                break;
            case 4: 
                cout<<"Enter account number of details to show: ";
                cin>>accnum;
                file.seekg(sizeof(Account) * (accnum-1));
                a = new Account();
                file.read(reinterpret_cast<char *>(a), sizeof(Account));
                a->display();
                delete a;
                file.clear();
                break;
            default:
                cout<<"Error, choose from 1 to 4"<<endl;
    }
    cout<<"Do you wish to continue? (Y/N)"<<endl;
    cin>>ch;

    }while(ch=='Y' || ch=='y');
    file.close();
    return 0;
}

