// Problem: Inorder Successor in BST
// Given a BST, and a reference to a Node k in the BST. Find the Inorder Successor of the given node in the BST. If there is no successor, return -1. 

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

// Helper function to find the in-order successor
void find(Node* root, Node* x, int &ans, bool &flag) {
    if (!root) return;

    find(root->left, x, ans, flag);

    if (flag && ans == -1) {
        ans = root->data;
        return;
    }

    if (root->data == x->data) {
        flag = true;
    }

    find(root->right, x, ans, flag);
}

// Returns the in-order successor value of node x
int inOrderSuccessor(Node* root, Node* x) {
    int ans = -1; // Use -1 to indicate "no successor"
    bool flag = false;
    find(root, x, ans, flag);
    return ans;
}

// Example usage
int main() {
    /*
        Construct the following BST:
               20
              /  \
            10    30
           / \     \
          5  15     40
    */

    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    Node* x = root->left;  // Node with value 10

    int successor = inOrderSuccessor(root, x);
    if (successor != -1)
        cout << "In-order successor of " << x->data << " is: " << successor << endl;
    else
        cout << "In-order successor of " << x->data << " does not exist." << endl;

    return 0;
}
