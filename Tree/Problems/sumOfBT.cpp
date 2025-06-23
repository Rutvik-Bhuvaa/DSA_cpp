#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to calculate sum of all nodes in binary tree
int sumBT(Node* root) {
    if (!root) {
        return 0;
    }
    return root->data + sumBT(root->left) + sumBT(root->right);
}

// Helper function to build a sample binary tree
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
    int totalSum = sumBT(root);
    cout << "Sum of all nodes in binary tree: " << totalSum << endl;
    return 0;
}
