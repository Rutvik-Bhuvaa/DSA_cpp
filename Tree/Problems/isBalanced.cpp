// Problem: Balanced Tree Check
// Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to calculate height and check balance
int height(Node* root, bool &ans) {
    if (!root) return 0;

    int left = height(root->left, ans);
    int right = height(root->right, ans);

    if (abs(left - right) > 1) {
        ans = false;
    }

    return 1 + max(left, right);
}

// Function to check if tree is balanced
bool isBalanced(Node* root) {
    bool ans = true;
    height(root, ans);
    return ans;
}

// Sample usage
int main() {
    /*
       Example Tree:
               1
              / \
             2   3
            /
           4
          /
         5
       => This tree is NOT balanced (left side deeper)
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);

    if (isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is NOT balanced." << endl;
    }

    return 0;
}
