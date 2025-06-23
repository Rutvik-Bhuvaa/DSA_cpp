#include <iostream>
using namespace std;

// Definition of a Node in the binary tree
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

// Function to count leaf nodes
int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

// Helper function to build a simple tree for testing
Node* createSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = createSampleTree();
    int leafCount = countLeaves(root);
    cout << "Number of leaf nodes: " << leafCount << endl;

    return 0;
}
