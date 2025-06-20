// Problem: Stack using two queues
// Implement a Stack using two queues q1 and q2.

#include <iostream>
#include <queue>
using namespace std;

class QueueStack {
private:
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Pop element from stack
    int pop() {
        if (q1.empty()) return -1;

        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
};

int main() {
    QueueStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Popped: " << s.pop() << endl; // 30
    cout << "Popped: " << s.pop() << endl; // 20
    s.push(40);
    cout << "Popped: " << s.pop() << endl; // 40
    cout << "Popped: " << s.pop() << endl; // 10
    cout << "Popped: " << s.pop() << endl; // -1 (empty)

    return 0;
}
