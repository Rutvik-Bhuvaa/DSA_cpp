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

// Inorder traversal to find kth smallest
void findKthSmallest(Node* root, int& k, int& ans) {
    if (!root || k <= 0) return;

    findKthSmallest(root->left, k, ans);
    k--;
    if (k == 0) {
        ans = root->data;
        return;
    }
    findKthSmallest(root->right, k, ans);
}

int kthSmallest(Node* root, int k) {
    int ans = -1;
    findKthSmallest(root, k, ans);
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
    cout << k << "rd smallest element: " << kthSmallest(root, k) << endl;

    return 0;
}
