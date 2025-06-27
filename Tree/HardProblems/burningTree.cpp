// Problem: . Amount of Time for Binary Tree to Be Infected(Burning tree)
// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

#include <iostream>
#include <algorithm>
#include <climits>
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

int Burn(TreeNode* root, int target, int &timer) {
    if (!root) return 0;

    if (root->val == target) return -1;

    int left = Burn(root->left, target, timer);
    int right = Burn(root->right, target, timer);

    if (left < 0) {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }

    if (right < 0) {
        timer = max(timer, abs(right) + left);
        return right - 1;
    }

    return max(left, right) + 1;
}

void find(TreeNode* root, int target, TreeNode* &temp) {
    if (!root) return;

    if (root->val == target) {
        temp = root;
        return;
    }

    find(root->left, target, temp);
    find(root->right, target, temp);
}

int height(TreeNode* temp) {
    if (!temp) return 0;

    return 1 + max(height(temp->left), height(temp->right));
}

int amountOfTime(TreeNode* root, int target) {
    int timer = 0;
    Burn(root, target, timer);
    TreeNode* temp = nullptr;
    find(root, target, temp);
    int num = height(temp) - 1;
    return max(timer, num);
}

// Sample main function to test
int main() {
    /*
        Sample Tree:
             1
            / \
           5   3
              / \
            10   6
        Target = 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    int target = 3;
    int time = amountOfTime(root, target);
    cout << "Amount of time to burn tree from target " << target << ": " << time << endl;

    // Cleanup
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
