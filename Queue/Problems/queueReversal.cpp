// Problem: Queue Reversal
// Given a queue q containing integer elements, your task is to reverse the queue.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the queue
queue<int> reverseQueue(queue<int>& q) {
    stack<int> s;

    // Push all elements into stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Pop from stack and push back into queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

// Helper function to print a queue
void printQueue(queue<int> q) {
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Adding elements to queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original ";
    printQueue(q);

    // Reverse the queue
    queue<int> reversedQ = reverseQueue(q);

    cout << "Reversed ";
    printQueue(reversedQ);

    return 0;
}
