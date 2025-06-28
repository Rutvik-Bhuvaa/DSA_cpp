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

// Insert into BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

// Find minimum value in BST
int minValue(Node* root) {
    if (!root) return -1;

    if (!root->left) return root->data;

    return minValue(root->left);
}

// Inorder Traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "Minimum value in BST: " << minValue(root) << endl;

    return 0;
}
