#include<iostream>
using namespace std;

int main(){
    int num = 10;
    int *p = &num;
    *p = 20;
    cout << p << endl;
    cout << num<< endl;
    return 0;
}