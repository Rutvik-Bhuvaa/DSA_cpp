#include<iostream>
using namespace std;

class Student{
    public:

    int rollNo;
    string name;
    string branch;
};

int main(){
    Student Obj;
    Obj.rollNo = 123;
    Obj.name = "Rutvikbhuvaa";
    Obj.branch = "IT";
    cout << Obj.rollNo << endl;
    cout << Obj.name << endl;
    cout << Obj.branch << endl;
    return 0;
}