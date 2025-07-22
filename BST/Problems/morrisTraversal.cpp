#include <iostream>
#include <vector>
using namespace std;

// Definition of the Binary Tree Node
class Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Morris Inorder Traversal Function
vector<int> morrisTraversal(Node* root) {
    vector<int> ans;

    while (root) {
        if (!root->left) {
            ans.push_back(root->data);
            root = root->right;
        } else {
            Node* curr = root->left;
            while (curr->right && curr->right != root) {
                curr = curr->right;
            }

            if (!curr->right) {
                curr->right = root; // Make thread
                root = root->left;
            } else {
                curr->right = nullptr; // Break thread
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }

    return ans;
}

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}

// Sample Usage
int main() {
    /*
            1
           / \
          2   3
         / \    
        4   5  
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> inorder = morrisTraversal(root);
    cout << "Morris Inorder Traversal: ";
    printVector(inorder);

    return 0;
}
