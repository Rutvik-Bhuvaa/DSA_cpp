#include<iostream>
using namespace std;

class Student{
    public:

    int rollNo;
    string name;
    string branch;
};

class Bank{
    // note: never write states using public access modifier if possible and use member functions to access this states
    public:
    int balance;
    string name;

    void setValue(int amount){
        balance += amount;
    }


    void checkBalance(){
        cout << balance << endl;
    }

    void withdraw(){
        balance-=100;
        cout << "100 rupees withdrawn successfully" << endl;
    }
};

class Car {
    int mileage; 
    int cost;
    // char c;

    public:
    // Basic constructor
    Car(){
        mileage = 10;
        cost = 200000;
        cout << "Hello constructor"<< endl;
    }

    // Parameterized constructor
    Car(int mileage, int cost){
        this->mileage = mileage;
        this->cost = cost;
        cout << "Parameterized constructor called" << endl;
    }

    void print(){
        cout << cost << " " << mileage << endl;
    }

    ~Car(){
        cout << "Destructor executed";
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
    customer.setValue(20000);
    customer.checkBalance();

    Car bmw;
    cout << sizeof(bmw) << endl;
    Car rangerover(10, 300000000);
    bmw.print();
    rangerover.print();
    return 0;
}