#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Reverse inorder to find kth largest
void findKthLargest(Node* root, int& k, int& ans) {
    if (!root || k <= 0) return;

    findKthLargest(root->right, k, ans);
    k--;
    if (k == 0) {
        ans = root->data;
        return;
    }
    findKthLargest(root->left, k, ans);
}

int kthLargest(Node* root, int k) {
    int ans = -1;
    findKthLargest(root, k, ans);
    return ans;
}

// Main function
int main() {
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    int k = 3;
    cout << k << "rd largest element: " << kthLargest(root, k) << endl;

    return 0;
}
