// Problem: Delete Mid of a Stack
// Given a stack s, delete the middle element of the stack without using any additional data structure.

// Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.

// Note: The output shown by the compiler is the stack from top to bottom.

#include<iostream>
#include<stack>
using namespace std;

void deleteMid(stack<int> &s){
    stack<int> temp;
    int count = s.size()/2;
    
    while(count--){
        temp.push(s.top());
        s.pop();
    }

    s.pop();

    while(temp.size()){
        s.push(temp.top());
        temp.pop();
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    deleteMid(s);

    printStack(s);

    return 0;
}