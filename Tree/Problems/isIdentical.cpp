// Problem: LC 100 Same Tree
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#include <iostream>
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

bool isSameTree(TreeNode* r1, TreeNode* r2) {
    if ((r1 && !r2) || (!r1 && r2)) {
        return false;
    }

    if (!r1 && !r2) {
        return true;
    }

    if (r1->val != r2->val) {
        return false;
    }

    return isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
}

// Sample usage
int main() {
    // Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    if (isSameTree(root1, root2)) {
        cout << "Both trees are the same." << endl;
    } else {
        cout << "Trees are different." << endl;
    }

    return 0;
}
