// Problem: Merge two BST 's
// Given two BSTs, return elements of merged BSTs in sorted form.

#include <iostream>
#include <vector>
using namespace std;

// Definition of the BST Node
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

// Inorder traversal to store elements in sorted order
void inorder(Node* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

// Merge two sorted arrays
vector<int> mergeSortedArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> merged;
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i++]);
        } else {
            merged.push_back(b[j++]);
        }
    }

    // Append remaining elements
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);

    return merged;
}

// Main function to merge two BSTs
vector<int> mergeBSTs(Node* root1, Node* root2) {
    vector<int> arr1, arr2;
    
    // Get sorted arrays
    inorder(root1, arr1);
    inorder(root2, arr2);

    // Merge both sorted arrays
    return mergeSortedArrays(arr1, arr2);
}

// --- For Testing Purpose ---
int main() {
    // Tree 1
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(6);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);

    // Tree 2
    Node* root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->right->right = new Node(7);
    root2->right->right->left = new Node(6);

    vector<int> merged = mergeBSTs(root1, root2);

    // Print result
    for (int val : merged) {
        cout << val << " ";
    }

    return 0;
}
