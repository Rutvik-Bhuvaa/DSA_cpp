#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Queue class using linked list
class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if queue is empty
    bool empty() {
        return front == nullptr;
    }

    // Enqueue operation
    void push(int value) {
        Node* newNode = new Node(value);
        if (empty()) {
            front = rear = newNode;
            rear->next = front; // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        cout << "Inserted: " << value << endl;
    }

    // Dequeue operation
    void pop() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        // Only one element
        if (front == rear) {
            cout << "Popped: " << front->data << endl;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            cout << "Popped: " << front->data << endl;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    // Display the queue
    void display() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

// Main function
int main() {
    CircularQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    q.pop();
    q.display();

    q.push(40);
    q.display();

    q.pop();
    q.pop();
    q.pop();
    q.display();

    return 0;
}
