// Problem: 199. Binary Tree Right Side View
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
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

// Function to get the Right View
vector<int> rightView(Node *root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            // Rightmost node of current level
            if (i == size - 1) {
                ans.push_back(temp->data);
            }

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
               5   4

        Expected Right View: 1 3 4
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    vector<int> result = rightView(root);

    cout << "Right View of Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
