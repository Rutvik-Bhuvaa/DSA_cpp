// Problem: K Sized Subarray Maximum
// Given an array arr[] of integers and an integer k, your task is to find 
// the maximum value for each contiguous subarray of size k. 
// The output should be an array of maximum values corresponding to each window.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    int n = arr.size();

    // First window
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    result.push_back(arr[dq.front()]);

    // Remaining windows
    for (int i = k; i < n; i++) {
        // Remove elements out of the window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements in current window
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
        result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 0, 5};
    int k = 3;

    vector<int> result = maxOfSubarrays(arr, k);

    cout << "Maximums in each subarray of size " << k << ":\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
