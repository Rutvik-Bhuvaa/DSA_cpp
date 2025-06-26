// Problem: Tree Boundary Traversal
// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

// Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

// Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

#include <iostream>
#include <vector>
using namespace std;

// Tree node definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void leftSubTree(Node* root, vector<int> &ans) {
    if (!root || (!root->left && !root->right)) return;

    ans.push_back(root->data);

    if (root->left)
        leftSubTree(root->left, ans);
    else
        leftSubTree(root->right, ans);
}

void leaves(Node* root, vector<int> &ans) {
    if (!root) return;

    if (!root->left && !root->right) {
        ans.push_back(root->data);
        return;
    }

    leaves(root->left, ans);
    leaves(root->right, ans);
}

void rightSubTree(Node* root, vector<int> &ans) {
    if (!root || (!root->left && !root->right)) return;

    if (root->right)
        rightSubTree(root->right, ans);
    else
        rightSubTree(root->left, ans);

    ans.push_back(root->data);  // Add after recursion to reverse order
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    if (!root->left && !root->right) {
        ans.push_back(root->data);
        return ans;
    }

    ans.push_back(root->data); // Root

    leftSubTree(root->left, ans);   // Left boundary
    leaves(root, ans);              // All leaf nodes
    rightSubTree(root->right, ans); // Right boundary (in reverse)

    return ans;
}

// Utility to print vector
void printVector(const vector<int>& v) {
    for (int val : v)
        cout << val << " ";
    cout << endl;
}

// Test driver
int main() {
    /*
          1
         / \
        2   3
       / \   \
      4   5   6
         / \ 
        7   8

    Boundary: 1 2 4 7 8 6 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    vector<int> result = boundaryTraversal(root);
    cout << "Boundary Traversal: ";
    printVector(result);

    return 0;
}
