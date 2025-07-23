// Problem: Ceil in BST
// Given a BST and a number X, find Ceil of X.
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

// If Ceil could not be found, return -1.


#include <iostream>
#include <climits>
using namespace std;

// Node class
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

// Insert into BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Function to find ceil
int findCeil(Node* root, int input) {
    int ceil = -1;

    while (root) {
        if (root->data == input) {
            return input;
        } else if (root->data < input) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}

int main() {
    Node* root = nullptr;
    int n, val, x;

    cout << "Enter number of nodes in BST: ";
    cin >> n;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter value to find ceil: ";
    cin >> x;

    int result = findCeil(root, x);
    cout << "Ceil of " << x << " is: " << result << endl;

    return 0;
}
