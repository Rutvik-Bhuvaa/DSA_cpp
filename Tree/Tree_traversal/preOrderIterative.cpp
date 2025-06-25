#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Iterative Preorder Traversal
vector<int> preOrder(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();

        ans.push_back(temp->data);

        // Push right first so left is processed first
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
    }

    return ans;
}

// Sample Tree:
//       1
//      / \
//     2   3
//    / \   \
//   4   5   6
Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    vector<int> result = preOrder(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
