#include <iostream>
#include <vector>
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

// Function to get nodes at odd levels
vector<int> nodesAtOddLevels(Node *root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            if (level % 2 != 0) {
                ans.push_back(temp->data);
            }

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        level++;
    }

    return ans;
}

// Helper function to build a simple binary tree
Node* buildSampleTree() {
    // Building this tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    Node* root = buildSampleTree();

    vector<int> result = nodesAtOddLevels(root);
    cout << "Nodes at odd levels: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
