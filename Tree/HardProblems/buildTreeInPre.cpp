// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

#include <iostream>
#include <vector>
using namespace std;

// TreeNode structure
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

// Function to find index in inorder
int find(vector<int> &inorder, int number, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == number) {
            return i;
        }
    }
    return -1;
}

// Build tree function
TreeNode* tree(vector<int> &preorder, vector<int> &inorder, int start, int end, int &index) {
    if (start > end) return nullptr;

    TreeNode* root = new TreeNode(preorder[index]);
    int i = find(inorder, preorder[index], start, end);
    index++;

    root->left = tree(preorder, inorder, start, i - 1, index);
    root->right = tree(preorder, inorder, i + 1, end, index);

    return root;
}

// Wrapper function
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    return tree(preorder, inorder, 0, inorder.size() - 1, index);
}

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main function for testing
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
