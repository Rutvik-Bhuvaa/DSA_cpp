// Problem: Print Nodes having K leaves
// Given a binary tree and an integer value K, the task is to find all nodes data in the given binary tree having exactly K leaves in sub-tree rooted with them.

// NOTE: Nodes should be printed in the order in which they appear in postorder traversal.

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive function to count leaf nodes and store nodes with exactly k leaves
int leafNodes(Node* ptr, int k, vector<int> &ans) {
    if (!ptr) return 0;

    if (!ptr->left && !ptr->right) return 1;

    int left = leafNodes(ptr->left, k, ans);
    int right = leafNodes(ptr->right, k, ans);

    int totalLeaves = left + right;

    if (totalLeaves == k) {
        ans.push_back(ptr->data);
    }

    return totalLeaves;
}

// Function to get all nodes whose subtree has exactly k leaf nodes
vector<int> btWithKleaves(Node *ptr, int k) {
    vector<int> ans;
    leafNodes(ptr, k, ans);
    if (ans.empty()) ans.push_back(-1);
    return ans;
}

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Sample tree builder for testing
Node* buildSampleTree() {
    // Tree:
    //     0
    //    / \
    //   1   2
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    int k = 1;

    vector<int> result = btWithKleaves(root, k);
    cout << "Output: ";
    printVector(result);

    return 0;
}
