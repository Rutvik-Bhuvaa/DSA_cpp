// Problem: 530. Minimum Absolute Difference in BST
// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

// Binary Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Function to insert nodes level-wise (used to build tree from array)
TreeNode* buildTree(const vector<string>& arr) {
    if (arr.empty() || arr[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (arr[i] != "null") {
            curr->left = new TreeNode(stoi(arr[i]));
            q.push(curr->left);
        }
        i++;
        if (i >= arr.size()) break;

        if (arr[i] != "null") {
            curr->right = new TreeNode(stoi(arr[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Solution class
class Solution {
public:
    int minDiff = INT_MAX;
    int prev = -1;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            minDiff = min(minDiff, abs(root->val - prev));
        }
        prev = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};

int main() {
    // Example input: BST [4,2,6,1,3]
    vector<string> arr = {"4", "2", "6", "1", "3"};
    TreeNode* root = buildTree(arr);

    Solution obj;
    int result = obj.getMinimumDifference(root);
    cout << "Minimum Absolute Difference: " << result << endl;

    return 0;
}
