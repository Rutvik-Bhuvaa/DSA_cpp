// Problem: String Manipulation
// Tom is a string freak. He has got sequences of words arr[] to manipulate. If in a sequence, two same words come together then Tom destroys each other. Find the number of words left in the sequence after this pairwise destruction. 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int removeConsecutiveSame(vector<string>& arr) {
    stack<string> s;
    int i = 0;
    while (i < arr.size()) {
        if (s.empty()) {
            s.push(arr[i]);
        } else {
            if (s.top() == arr[i]) {
                s.pop(); // Destroy the pair
            } else {
                s.push(arr[i]);
            }
        }
        i++;
    }
    return s.size();
}

int main() {
    // Test Case 1
    vector<string> arr1 = {"ab", "aa", "aa", "bcd", "ab"};
    cout << "Output: " << removeConsecutiveSame(arr1) << endl;

    // Test Case 2
    vector<string> arr2 = {"tom", "jerry", "jerry", "tom"};
    cout << "Output: " << removeConsecutiveSame(arr2) << endl;

    return 0;
}
