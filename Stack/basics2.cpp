// Stack implementation using linked list

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Stack{
    Node *top;
    public:
    Stack(){
        top = nullptr;
    }

    // push element
    void push(int data){
        Node *temp =  new Node(data);

        if(!temp){
            cout << "Stack overflow" << endl;
            return;
        }

        temp->next = top;
        top = temp;
    }

    // pop element
    void pop(){
        if(!top){
            cout << "Stack underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    // peak element
    int peak(){
        if(!top){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool empty(){
        return top == nullptr;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peak() << endl;
    s.pop();
    cout << "Top element after pop: " << s.peak() << endl;

    return 0;
}