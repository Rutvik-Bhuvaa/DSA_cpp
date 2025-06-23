// Problem: Minimum Number of K Consecutive Bit Flips
// You are given a binary array nums and an integer k.

// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

// A subarray is a contiguous part of an array.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
    int flip = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        // Remove expired flips
        if (!q.empty() && q.front() == i - k)
            q.pop();

        // If current bit needs flipping
        if (q.size() % 2 == nums[i]) {
            if (i + k > n)
                return -1;  // Not enough space left to flip
            flip++;
            q.push(i);  // Start a flip at position i
        }
    }

    return flip;
}

int main() {
    vector<int> nums = {0, 1, 0};
    int k = 1;

    int result = kBitFlips(nums, k);
    cout << "Minimum number of K-bit flips: " << result << endl;

    return 0;
}