// Problem: Max Path Sum 2 Special Nodes
// Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special node to another special node.

// Note: Here special node is a node that is connected to exactly one different node.

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Function to find max path sum between two leaves
int maxSum(TreeNode* root, int &sum, bool &isLeafPathFound) {
    if (!root) return 0;

    // If leaf node
    if (!root->left && !root->right) return root->val;

    int left = maxSum(root->left, sum, isLeafPathFound);
    int right = maxSum(root->right, sum, isLeafPathFound);

    if (root->left && root->right) {
        sum = max(sum, left + right + root->val);
        isLeafPathFound = true;
        return root->val + max(left, right);
    }

    return root->val + (root->left ? left : right);
}

int maxPathSum(TreeNode* root) {
    int sum = INT_MIN;
    bool isLeafPathFound = false;
    int val = maxSum(root, sum, isLeafPathFound);

    return isLeafPathFound ? sum : val;
}

int main() {
    // Hardcoded tree: [2, -1]
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(-1);

    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;

    // Cleanup
    delete root->left;
    delete root;

    return 0;
}
