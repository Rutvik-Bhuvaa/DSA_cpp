// stack implementation using array
#include<iostream>
using namespace std;

class Stack{
    
    int top;
    int *arr;
    int size;

    public:
    Stack(int size){
        arr = new int[size];
        top = -1;
        this->size = size;
    }

    void push(int data){
        if(top == size-1){
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop(){
        if(top == -1){
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
        return;
    }

    int peek(){
        if(top == -1){
            cout << "Stack underflow" << endl;
            return -1;
        }

        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};


int main(){
    Stack s(4);
    s.push(4);
    s.push(3);
    cout << s.peek();
    return 0;
}