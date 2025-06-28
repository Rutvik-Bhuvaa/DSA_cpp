#include <iostream>
using namespace std;

// Node structure for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a node into BST
Node* BST(Node* root, int value) {
    if (!root) {
        root = new Node(value);
        return root;
    }

    // Left Subtree
    if (value < root->data) {
        root->left = BST(root->left, value);
    }
    // Right Subtree
    else {
        root->right = BST(root->right, value);
    }

    return root;
}

// Inorder Traversal of BST (Sorted Order)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    int arr[10] = {10, 13, 4, 8, 11, 19, 2, 7, 18, 23};
    Node* root = nullptr;

    // Insert elements into BST
    for (int i = 0; i < 10; i++) {
        root = BST(root, arr[i]);
    }

    // Display inorder traversal
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
