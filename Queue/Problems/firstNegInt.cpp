// Problem: First negative in every window of size k
// Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

// Note: If a window does not contain a negative integer, then return 0 for that window.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> firstNegInt(vector<int>& arr, int k) {
    vector<int> ans;
    queue<int> q;

    // Preprocess the first k-1 elements
    for (int i = 0; i < k - 1; i++) {
        if (arr[i] < 0) {
            q.push(i);
        }
    }

    // Process the remaining elements
    for (int i = k - 1; i < arr.size(); i++) {
        if (arr[i] < 0) {
            q.push(i);
        }

        // Add the first negative integer of the current window
        if (q.empty()) {
            ans.push_back(0);
        } else {
            ans.push_back(arr[q.front()]);
        }

        // Remove elements that are out of this window
        if (!q.empty() && q.front() <= i - k + 1) {
            q.pop();
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = firstNegInt(arr, k);
    
    cout << "First negative integers in every window of size " << k << " are:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
