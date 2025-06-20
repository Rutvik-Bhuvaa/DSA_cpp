#include<iostream>
using namespace std;

class Queue{
    int front;
    int rear;
    int *arr;
    int size;

    public: 
    Queue(int size){
        front = 0;
        rear = 0;
        this->size = size;
        arr = new int[size];
    }

    void push(int data){
        if(rear == size){
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    void pop(){
        if(front == rear){
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
    }

    bool empty(){
        return front==rear;
    }
};

int main(){
    Queue q(5);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);
    q.pop();
    q.push(55);

    return 0;
}