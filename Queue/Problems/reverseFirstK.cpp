// Problem: Reverse first K of a Queue
// Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

// "If the size of queue is smaller than the given k , then return the original queue."

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse first K elements of a queue
queue<int> reverseFirstK(queue<int> q, int k) {
    if (q.size() < k || k < 0)
        return q;  // Return original queue if k is invalid

    stack<int> s;

    // Step 1: Push first k elements into the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue stack elements back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move remaining elements to the back
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

// Main function to test
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    queue<int> result = reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
