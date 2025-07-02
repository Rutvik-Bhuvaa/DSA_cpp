// Problem:  Flatten Binary Tree to Linked List
// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
#include <iostream>
using namespace std;

// Definition for binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Flatten function using modified Morris traversal
void flatten(Node* root) {
    while (root) {
        if (root->left) {
            Node* curr = root->left;

            // Find the rightmost node in left subtree
            while (curr->right) {
                curr = curr->right;
            }

            // Connect original right subtree to rightmost node
            curr->right = root->right;

            // Move left subtree to right and nullify left
            root->right = root->left;
            root->left = nullptr;
        }

        // Move to the next node (always right)
        root = root->right;
    }
}

// Helper function to print the right-skewed tree (flattened list)
void printRightSkewed(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

// Example usage
int main() {
    /*
        Construct the following tree:
               1
              / \
             2   5
            / \   \
           3   4   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    cout << "Flattening the binary tree...\n";
    flatten(root);

    cout << "Right-skewed flattened tree: ";
    printRightSkewed(root);

    return 0;
}

