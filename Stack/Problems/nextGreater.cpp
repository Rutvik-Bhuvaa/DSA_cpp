// Problem: Next Greater Element
// Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
    stack<int> s;
    vector<int> ans(arr.size()); // Initialize ans with same size as arr
    int i = 0;

    while (i < arr.size()) {
        if (s.empty()) {
            s.push(i);
        } else {
            if (arr[s.top()] >= arr[i]) {
                s.push(i);
            } else {
                while (!s.empty() && arr[s.top()] < arr[i]) {
                    ans[s.top()] = arr[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        i++;
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 25}; // Sample input
    vector<int> result = nextLargerElement(arr);

    cout << "Next greater elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
