// Problem: Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;  // First level is Left to Right

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (!leftToRight)
            reverse(level.begin(), level.end());

        result.push_back(level);
        leftToRight = !leftToRight; // Flip direction
    }

    return result;
}

// Helper to print zigzag levels
void printZigzag(const vector<vector<int>>& res) {
    for (auto level : res) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }
}

// Sample usage
int main() {
    // Build test tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> result = zigzagLevelOrder(root);
    printZigzag(result);

    return 0;
}
