// Problem: Floor in BST
// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

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

// Function to find floor in BST
int findFloor(Node* root, int input) {
    int floor = -1;

    while (root) {
        if (root->data == input) {
            return input;
        } else if (root->data > input) {
            root = root->left;
        } else {
            floor = root->data;
            root = root->right;
        }
    }

    return floor;
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

    cout << "Enter value to find floor: ";
    cin >> x;

    int result = findFloor(root, x);
    cout << "Floor of " << x << " is: " << result << endl;

    return 0;
}
