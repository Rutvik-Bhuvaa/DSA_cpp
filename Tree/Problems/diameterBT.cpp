// Problem: Diameter of Binary Tree
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.


#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to find diameter
int find(TreeNode* root, int &ans) {
    if (!root) {
        return 0;
    }

    int left = find(root->left, ans);
    int right = find(root->right, ans);

    ans = max(ans, left + right);

    return 1 + max(left, right);
}

// Main function to calculate diameter
int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    find(root, ans);
    return ans;
}

// Sample usage
int main() {
    /*
       Example Tree:
              1
             / \
            2   3
           / \
          4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the binary tree is: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
