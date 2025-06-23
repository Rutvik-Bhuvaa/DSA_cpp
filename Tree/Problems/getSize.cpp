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

// Function to calculate the size (total number of nodes)
int getSize(Node* node) {
    if (!node) {
        return 0;
    }
    return 1 + getSize(node->left) + getSize(node->right);
}

// Sample tree for testing
Node* createSampleTree() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    return root;
}

int main() {
    Node* root = createSampleTree();
    int size = getSize(root);
    cout << "Total number of nodes: " << size << endl;
    return 0;
}
