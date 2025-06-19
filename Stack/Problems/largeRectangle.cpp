// Problem : Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

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

int getMaxArea(vector<int> &arr) {
    int n = arr.size();
    vector<int> right(n, n);  // default: no smaller on right
    vector<int> left(n, -1);  // default: no smaller on left

    push_right(arr, right);
    push_left(arr, left);

    long long area = 0;

    for (int i = 0; i < n; i++) {
        long long width = right[i] - left[i] - 1;
        long long current_area = width * arr[i];
        area = max(area, current_area);
    }

    return area;
}

int main() {
    vector<int> histogram = {6, 2, 5, 4, 5, 1, 6};

    int max_area = getMaxArea(histogram);
    cout << "Maximum Area in Histogram: " << max_area << endl;

    return 0;
}
