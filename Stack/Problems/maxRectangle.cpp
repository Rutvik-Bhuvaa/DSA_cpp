// Problem: Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to compute right[] (next smaller to right)
void push_right(vector<int> &arr, vector<int> &right) {
    stack<int> s;
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
}

// Function to compute left[] (next smaller to left)
void push_left(vector<int> &arr, vector<int> &left) {
    stack<int> s;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
}

// Main function to find max rectangle area in binary matrix
int maxArea(vector<vector<int>> &M) {
    int n = M.size();
    int m = M[0].size();
    vector<int> sum(m, 0);
    int max_area = 0;

    for (int i = 0; i < n; i++) {
        // Step 1: Build histogram
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 1)
                sum[j]++;
            else
                sum[j] = 0;
        }

        // Step 2: Calculate area using histogram
        vector<int> right(m, m);
        vector<int> left(m, -1);
        push_right(sum, right);
        push_left(sum, left);

        for (int j = 0; j < m; j++) {
            int width = right[j] - left[j] - 1;
            int area = width * sum[j];
            max_area = max(max_area, area);
        }
    }

    return max_area;
}

int main() {
    // Sample binary matrix
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int result = maxArea(matrix);
    cout << "Maximum Rectangle Area = " << result << endl;

    return 0;
}
