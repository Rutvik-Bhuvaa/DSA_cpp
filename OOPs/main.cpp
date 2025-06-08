#include<iostream>
using namespace std;

class Student{
    public:

    int rollNo;
    string name;
    string branch;
};

class Bank{
    public:
    int balance;
    string name;


    void checkBalance(){
        cout << balance << endl;
    }

    void withdraw(){
        balance-=100;
        cout << "100 rupees withdrawn successfully" << endl;
    }
};

int main(){
    Student Obj;
    Obj.rollNo = 123;
    Obj.name = "Rutvikbhuvaa";
    Obj.branch = "IT";
    cout << Obj.rollNo << endl;
    cout << Obj.name << endl;
    cout << Obj.branch << endl;

    Bank customer;
    customer.balance = 20000;
    customer.name = "Rutvik Bhuvaa";
    customer.checkBalance();
    customer.withdraw();
    customer.checkBalance();
    return 0;
}