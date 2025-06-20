// Problem: Queue using two Stacks
// Implement a Queue using 2 stacks s1 and s2 .
// A Query q is of 2 Types
// (i) 1 x (a query of this type means  pushing 'x' into the queue)
// (ii) 2   (a query of this type means to pop element from queue and print the poped element)

// Note : If there is no element return -1 as answer while popping.


#include <iostream>
#include <stack>
using namespace std;

class StackQueue {
private:
    stack<int> s1, s2;

public:
    // Push element into the queue
    void push(int B) {
        s1.push(B);
    }

    // Pop element from the queue
    int pop() {
        if (s1.empty() && s2.empty())
            return -1;

        if (!s2.empty()) {
            int data = s2.top();
            s2.pop();
            return data;
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int data = s2.top();
        s2.pop();
        return data;
    }
};

int main() {
    StackQueue q;

    // Insert elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Pop elements
    cout << "Popped: " << q.pop() << endl; // 10
    q.push(40);
    cout << "Popped: " << q.pop() << endl; // 20
    cout << "Popped: " << q.pop() << endl; // 30
    cout << "Popped: " << q.pop() << endl; // 40
    cout << "Popped: " << q.pop() << endl; // -1 (empty)

    return 0;
}
