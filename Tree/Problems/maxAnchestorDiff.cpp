// Problem: Maximum Difference Between Node and Ancestor
// Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

// A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

// Function to find max difference between ancestor and node
void find(TreeNode* root, int anc_max, int anc_min, int &diff) {
    if (!root) return;

    diff = max(diff, max(abs(anc_max - root->val), abs(anc_min - root->val)));

    anc_max = max(anc_max, root->val);
    anc_min = min(anc_min, root->val);

    find(root->left, anc_max, anc_min, diff);
    find(root->right, anc_max, anc_min, diff);
}

int maxAncestorDiff(TreeNode* root) {
    if (!root) return 0;
    int diff = 0;
    find(root, root->val, root->val, diff);
    return diff;
}

// Builds the tree: [1,null,2,null,0,3]
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(0);
    root->right->right->left = new TreeNode(3);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    int result = maxAncestorDiff(root);
    cout << "Maximum Ancestor Difference: " << result << endl;
    return 0;
}
