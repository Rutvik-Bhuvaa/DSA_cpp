// Problem: Construct Binary Tree from Inorder and Postorder Traversal
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 


#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

int find(vector<int> &inorder, int value, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value) return i;
    }
    return -1;
}

TreeNode* buildFromPostIn(vector<int> &postorder, vector<int> &inorder, int start, int end, int &index) {
    if(start > end) return nullptr;

    TreeNode* root = new TreeNode(postorder[index--]);
    int pos = find(inorder, root->val, start, end);

    // Important: build right subtree first in postorder
    root->right = buildFromPostIn(postorder, inorder, pos + 1, end, index);
    root->left = buildFromPostIn(postorder, inorder, start, pos - 1, index);

    return root;
}

TreeNode* buildTreePostIn(vector<int>& inorder, vector<int>& postorder) {
    int index = postorder.size() - 1;
    return buildFromPostIn(postorder, inorder, 0, inorder.size() - 1, index);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTreePostIn(inorder, postorder);
    cout << "Inorder traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
}
