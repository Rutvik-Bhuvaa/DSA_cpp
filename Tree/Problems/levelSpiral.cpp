// Problem: Level Order in spiral form
// Given a binary tree and the task is to find the spiral order traversal of the tree and return the list containing the elements.
// Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.
// For below tree, function should return [1, 2, 3, 4, 5, 6, 7]

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> findSpiral(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);
    bool revFlag = true;  // Rename to avoid conflict with std::reverse

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i) {
            Node* curr = q.front();
            q.pop();
            level.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (revFlag)
            std::reverse(level.begin(), level.end()); // Now works

        for (int val : level)
            result.push_back(val);

        revFlag = !revFlag;
    }

    return result;
}

// Test driver
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> res = findSpiral(root);
    cout << "Spiral Order: ";
    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
