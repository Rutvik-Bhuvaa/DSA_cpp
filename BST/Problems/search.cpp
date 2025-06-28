#include <iostream>
using namespace std;

// Node structure
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

// Search in BST
bool search(Node* root, int x) {
    if (!root) return false;
    if (root->data == x) return true;

    if (x < root->data) return search(root->left, x);
    else return search(root->right, x);
}

// Inorder traversal for verification
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int arr[] = {10, 5, 15, 2, 7, 12, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    int x = 7;
    if (search(root, x)) {
        cout << x << " found in BST.\n";
    } else {
        cout << x << " not found in BST.\n";
    }

    return 0;
}
