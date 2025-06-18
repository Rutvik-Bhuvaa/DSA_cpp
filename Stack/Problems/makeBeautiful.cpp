// Problem: Make the array beautiful
// Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

// If two adjacent integers are different i.e. one of them is negative and other is non-negative, remove them.
// Return the beautiful array after performing the above operation.

// Note:An empty array is also a beautiful array. There can be many adjacent integers which are different as stated above. So remove different adjacent integers as described above from left to right.

#include <iostream>
#include <vector>
using namespace std;

// Function to make the array beautiful
vector<int> makeBeautiful(vector<int> arr) {
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {

        // Check if stack (ans) is not empty and top is opposite sign
        if (!ans.empty() && ((ans.back() >= 0 && arr[i] < 0) || (ans.back() < 0 && arr[i] >= 0))) {
            ans.pop_back(); // Cancel both
        } else {
            ans.push_back(arr[i]); // Push if no cancellation
        }
    }

    return ans;
}

int main() {
    // Sample input
    vector<int> arr = {4, -3, -2, 1, -1};

    // Call function
    vector<int> result = makeBeautiful(arr);

    // Output final result
    cout << "Final Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
