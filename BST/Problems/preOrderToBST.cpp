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

// Function to build BST from preorder
Node* buildBST(int pre[], int size, int min, int max, int &index) {
    if (index >= size || pre[index] < min || pre[index] > max)
        return nullptr;

    Node* root = new Node(pre[index]);
    index++;

    root->left = buildBST(pre, size, min, root->data, index);
    root->right = buildBST(pre, size, root->data, max, index);

    return root;
}

// Inorder traversal to verify the tree
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int preorder[] = {8, 5, 1, 7, 10, 12};
    int size = sizeof(preorder) / sizeof(preorder[0]);
    int index = 0;

    Node* root = buildBST(preorder, size, INT_MIN, INT_MAX, index);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
