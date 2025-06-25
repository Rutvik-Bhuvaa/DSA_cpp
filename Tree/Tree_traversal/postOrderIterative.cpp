#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // for reverse()
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

// Iterative Postorder Traversal using one stack and reverse
vector<int> postOrder(Node* node) {
    vector<int> ans;
    if (!node) return ans;

    stack<Node*> s;
    s.push(node);

    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();

        // Push left and right children
        if (temp->left) s.push(temp->left);
        if (temp->right) s.push(temp->right);

        // Collect data
        ans.push_back(temp->data);
    }

    // Reverse to get postorder (left → right → root)
    reverse(ans.begin(), ans.end());
    return ans;
}

// Sample binary tree:
//        1
//       / \
//      2   3
//     / \
//    4   5
Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    vector<int> result = postOrder(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
