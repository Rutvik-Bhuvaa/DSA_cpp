#include <iostream>
using namespace std;

// Node structure for Binary Tree
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

// Helper function to check BST using inorder traversal
void find(Node* root, Node* &prev, bool &ans) {
    if (!root || !ans) return;

    find(root->left, prev, ans);

    if (prev && prev->data >= root->data) {
        ans = false;
        return;
    }

    prev = root;

    find(root->right, prev, ans);
}

// Main function to check if the tree is a BST
bool isBST(Node* root) {
    Node* prev = nullptr;
    bool ans = true;
    find(root, prev, ans);
    return ans;
}

// Utility function to insert nodes in BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Driver Code
int main() {
    // Test case: Tree with INT_MIN
    Node* root = new Node(-2147483648); // INT_MIN

    if (isBST(root))
        cout << "It is a BST" << endl;
    else
        cout << "It is NOT a BST" << endl;

    return 0;
}
