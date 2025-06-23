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

// Function to count non-leaf nodes
int countNonLeafNodes(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;  // Base case: null or leaf node
    }
    
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// Sample tree builder
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
    int nonLeafCount = countNonLeafNodes(root);
    cout << "Number of non-leaf nodes: " << nonLeafCount << endl;
    return 0;
}
