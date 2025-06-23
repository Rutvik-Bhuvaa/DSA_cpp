// Problem: 239. Sliding Window Maximum
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Function to find the maximum in each sliding window of size B
vector<int> maxSlidingWindow(vector<int>& A, int B) {
    vector<int> v;
    if (A.size() == 0)
        return v;

    deque<int> d;
    int i = 0, n = A.size();

    // Process first B elements
    for (i = 0; i < B; i++) {
        while (!d.empty() && A[d.back()] < A[i])
            d.pop_back();
        d.push_back(i);
    }

    v.push_back(A[d.front()]);
    if (B == A.size())
        return v;

    // Process the rest of the array
    for (; i < n; i++) {
        // Remove elements out of this window
        if (!d.empty() && d.front() <= i - B)
            d.pop_front();

        // Remove all elements smaller than the current one
        while (!d.empty() && A[d.back()] < A[i])
            d.pop_back();

        d.push_back(i);
        v.push_back(A[d.front()]);
    }

    return v;
}

int main() {
    vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    int B = 3;

    vector<int> result = maxSlidingWindow(A, B);

    cout << "Maximums in each sliding window of size " << B << ":\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
