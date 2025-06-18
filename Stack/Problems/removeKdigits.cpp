// Problem: Remove K Digits
// Given a non-negative integer s represented as a string, remove k digits from the number so that the new number is the smallest possible.
// Note : The given number does not contain any leading zero.


#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeKdigits(string S, int K) {
    stack<int> st;
    int i = 0, num;

    // Step 1: Process each digit
    while (i < S.size()) {
        num = S[i] - '0';

        // Step 2: Remove larger digits from stack to make number smaller
        while (!st.empty() && st.top() > num && K > 0) {
            st.pop();
            K--;
        }

        st.push(num);
        i++;
    }

    // Step 3: If K digits are still left to remove, pop from end
    while (K-- && !st.empty()) {
        st.pop();
    }

    // Step 4: Build result string from stack
    string ans;
    while (!st.empty()) {
        ans += (st.top() + '0');
        st.pop();
    }

    // Step 5: Reverse to correct order
    reverse(ans.begin(), ans.end());

    // Step 6: Remove leading zeros
    int start = 0;
    while (start < ans.size() && ans[start] == '0') {
        start++;
    }

    ans = ans.substr(start);

    // Step 7: If empty string, return "0"
    return ans.empty() ? "0" : ans;
}

int main() {
    string S;
    int K;

    cout << "Enter number string: ";
    cin >> S;

    cout << "Enter K (number of digits to remove): ";
    cin >> K;

    string result = removeKdigits(S, K);
    cout << "Smallest possible number: " << result << endl;

    return 0;
}
