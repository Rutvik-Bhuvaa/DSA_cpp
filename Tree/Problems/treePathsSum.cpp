// Problem: 129. Sum Root to Leaf Numbers
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to calculate sum of all root-to-leaf numbers
int totalSum(Node* root, int sum) {
    if (!root) return 0;

    sum = sum * 10 + root->data;

    if (!root->left && !root->right)
        return sum;

    int left = totalSum(root->left, sum);
    int right = totalSum(root->right, sum);

    return left + right;
}

int treePathsSum(Node *root) {
    return totalSum(root, 0);
}

// Sample Tree:
//        1
//       / \
//      2   3
// Paths: 12 and 13 => Output: 25

Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    cout << "Sum of all root-to-leaf paths: " << treePathsSum(root) << endl;
    return 0;
}
