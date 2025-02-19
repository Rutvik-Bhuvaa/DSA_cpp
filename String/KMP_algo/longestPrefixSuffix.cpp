// Given a string of characters s, find the length of the longest prefix which is also a suffix.
// Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

#include<iostream>
using namespace std;

int longestPrefixSuffix(string str) {
    int n = str.size();
    int lps[n] = {0}; // LPS array

    int first = 0; // Length of the previous longest prefix-suffix
    int second = 1; // Index to process

    while (second < n) {
        if (str[first] == str[second]) {
            first++;
            lps[second] = first;
            second++;
        } else {
            if (first == 0) {
                lps[second] = 0;
                second++;
            } else {
                first = lps[first - 1]; // Move `first` to a previous matching length
            }
        }
    }

    return lps[n - 1]; // The last value in LPS array gives the answer
}

int main(){
    string str; 
    cout << "Enter the string: ";
    cin >> str;

    int result = longestPrefixSuffix(str);
    cout << "Longest common prefix and suffix length is: " << result;
    return 0;
}