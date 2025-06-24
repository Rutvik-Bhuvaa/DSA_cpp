// Problem: Left View of Binary Tree
// You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

// If the tree is empty, return an empty list.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node definition for Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to get the Left View
vector<int> leftView(Node *root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        ans.push_back(q.front()->data); // leftmost node of the level

        while (size--) {
            Node* temp = q.front();
            q.pop();

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return ans;
}

// Main function to test
int main() {
    /*
         Sample Tree:
               1
              / \
             2   3
              \   \
               4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = leftView(root);

    cout << "Left View of Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
