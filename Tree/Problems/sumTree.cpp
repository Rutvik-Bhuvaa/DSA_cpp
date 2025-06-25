// Problem: Sum Tree
// Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

// A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check if tree is a Sum Tree
int sum(Node* root, bool &ans) {
    if (!root) return 0;

    // If leaf node, return its value
    if (!root->left && !root->right)
        return root->data;

    // Recursive sum of left and right
    int left = sum(root->left, ans);
    int right = sum(root->right, ans);

    // Check sum tree condition
    if (left + right != root->data)
        ans = false;

    return root->data + left + right;
}

bool isSumTree(Node* root) {
    bool ans = true;
    sum(root, ans);
    return ans;
}

// Sample tree builder:
//        26
//       /  \
//     10    3
//    / \     \
//   4   6     3
Node* buildSampleTree() {
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    return root;
}

int main() {
    Node* root = buildSampleTree();

    if (isSumTree(root))
        cout << "This is a Sum Tree." << endl;
    else
        cout << "This is NOT a Sum Tree." << endl;

    return 0;
}
