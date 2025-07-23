// Problem: Closest in BST
// Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

#include <iostream>
#include <climits>
using namespace std;

// Node class definition
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

// Function to find minimum absolute difference
int minDiff(Node* root, int K) {
    if (!root) return INT_MAX;

    if (K == root->data) return 0;
    else if (K > root->data)
        return min(K - root->data, minDiff(root->right, K));
    else
        return min(root->data - K, minDiff(root->left, K));
}

int main() {
    Node* root = nullptr;
    int n, val, K;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter value of K: ";
    cin >> K;

    int result = minDiff(root, K);
    cout << "Minimum absolute difference with " << K << " is: " << result << endl;

    return 0;
}
