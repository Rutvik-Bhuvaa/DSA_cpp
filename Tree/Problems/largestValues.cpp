// Problem: Find Largest Value in Each Tree Row
// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

// Function to find largest value at each level
vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            maxVal = max(maxVal, node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(maxVal);
    }

    return result;
}

// Sample tree builder:
//         1
//        / \
//       3   2
//      / \   \
//     5   3   9
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    vector<int> result = largestValues(root);

    cout << "Largest values at each level: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


 