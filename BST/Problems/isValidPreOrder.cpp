//Problem: Preorder Traversal and BST

//  Given an array arr[ ] of size N consisting of distinct integers, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.
#include <iostream>
#include <climits>
using namespace std;

bool isValidPreorder(int pre[], int size, int min, int max, int& index) {
    if (index >= size)
        return true;

    // Current element must be within allowed min-max range
    if (pre[index] < min || pre[index] > max)
        return true;  // Do NOT increment index, just return true to continue

    int val = pre[index];
    index++;

    // Validate left and right subtrees
    bool leftValid = isValidPreorder(pre, size, min, val, index);
    bool rightValid = isValidPreorder(pre, size, val, max, index);

    return leftValid && rightValid;
}

int canRepresentBST(int pre[], int size) {
    int index = 0;
    bool result = isValidPreorder(pre, size, INT_MIN, INT_MAX, index);
    return (index == size && result) ? 1 : 0;
}

int main() {
    int pre[] = {10, 5, 1, 7, 40, 50}; // Try with other test cases
    int size = sizeof(pre) / sizeof(pre[0]);

    cout << canRepresentBST(pre, size) << endl;

    return 0;
}
