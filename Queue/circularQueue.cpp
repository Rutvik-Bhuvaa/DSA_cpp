#include<iostream>
using namespace std;

class CircularQueue{
    int front;
    int rear;
    int *arr;
    int size;

    public: 
    CircularQueue(int size){
        front = -1;
        rear = -1;
        this->size = size;
        arr = new int[size];
    }

    bool empty(){
        return front == -1 && rear == -1;
    }

    bool full(){
        return front == (rear+1)%size;
    }

    void push(int data){
        if(empty()){
            front = 1;
            rear = 1;
            arr[rear] = data;
            return;
        }else if(full()){
            cout << "Queue is full" << endl;
            return;
        }else{
            rear = (rear+1)%size;
            arr[rear] = data;
            return;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        } else if (front == rear) {
            // Only one element in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
    
};

int main(){
    CircularQueue cq(5);
    cq.push(10);

    return 0;
}