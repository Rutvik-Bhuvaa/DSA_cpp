#include <iostream>
#include <queue>
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

// Function to build tree in level-order
Node* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int x;
    cin >> x;

    if (x == -1) return nullptr;

    Node* root = new Node(x);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

// Height of tree (in terms of edges)
int height(Node* node) {
    if (!node) return -1;  // Important: -1 for null means 0 height for leaf

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = buildTree();
    int h = height(root);
    cout << "Height of the binary tree (in edges): " << h << endl;
    return 0;
}
