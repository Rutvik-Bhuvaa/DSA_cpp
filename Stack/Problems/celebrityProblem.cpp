// Problem: The Celebrity Problem
// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the celebrity
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();  // Get number of people (rows)

    stack<int> s;

    // Step 1: Push all people into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {
        int A = s.top(); s.pop();
        int B = s.top(); s.pop();

        if (mat[A][B] == 1) {
            // A knows B → A is not a celebrity
            s.push(B);
        } else {
            // A doesn't know B → B is not a celebrity
            s.push(A);
        }
    }

    if (s.empty()) return -1;

    // Step 3: Verify the remaining person
    int candidate = s.top();

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // Celebrity knows no one AND everyone knows celebrity
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }
    }

    return candidate;
}

int main() {
    // Example input
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int result = celebrity(mat);
    
    if (result == -1)
        cout << "No Celebrity Found" << endl;
    else
        cout << "Celebrity Index: " << result << endl;

    return 0;
}
