// Problem: Sum of k smallest elements in BST
// Given a Binary Search Tree. Find sum of all elements smaller than and equal to Kth smallest element.

#include <iostream>
using namespace std;

// Definition for the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper function to perform in-order traversal
void find(Node* root, int &k, int &total) {
    if (!root) return;

    find(root->left, k, total);

    k--;
    if (k >= 0)
        total += root->data;

    find(root->right, k, total);
}

// Main function to return sum of first k smallest elements
int sum(Node* root, int k) {
    int total = 0;
    find(root, k, total);
    return total;
}

// Example usage
int main() {
    /*
        Construct the following BST:
               5
              / \
             3   8
            / \   \
           2   4   9
    */

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    int k = 3;
    cout << "Sum of first " << k << " smallest elements: " << sum(root, k) << endl;

    return 0;
}
