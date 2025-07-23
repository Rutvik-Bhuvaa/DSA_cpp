// Problem: 99. Recover Binary Search Tree/Fixing Two nodes of a BST
// Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original Binary search tree(BST).

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// === YOUR CODE: Fix swapped nodes in BST ===
void find(Node* root, Node*& prev, Node*& first, Node*& second) {
    if (!root) return;

    find(root->left, prev, first, second);

    if (prev && prev->data > root->data) {
        if (!first && !second) {
            first = prev;
            second = root;
        } else {
            second = root;
        }
    }

    prev = root;

    find(root->right, prev, first, second);
}

void correctBST(Node* root) {
    Node *prev = nullptr, *first = nullptr, *second = nullptr;
    find(root, prev, first, second);
    if (first && second) {
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
    }
    return;
}

// === Inorder traversal to check correctness ===
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// === Build BST from level order input ===
Node* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front(); q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new Node(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    // Example: BST with two swapped nodes: [10,5,8] → 8 & 5 are swapped
    vector<string> levelOrder = {"10", "8", "5"};  // Correct would be: 10,5,8

    Node* root = buildTree(levelOrder);

    cout << "Before correction (Inorder): ";
    inorder(root);
    cout << endl;

    correctBST(root);

    cout << "After correction (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
