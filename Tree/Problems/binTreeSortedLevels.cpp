#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> binTreeSortedLevels(int arr[], int n) {
    vector<vector<int>> result;
    
    int level = 0;          // Start from level 0
    int index = 0;          // Index in input array

    while (index < n) {
        int nodesInLevel = 1 << level;  // 2^level nodes
        vector<int> currentLevel;

        for (int i = 0; i < nodesInLevel && index < n; i++) {
            currentLevel.push_back(arr[index]);
            index++;
        }

        sort(currentLevel.begin(), currentLevel.end());
        result.push_back(currentLevel);

        level++;  // Move to next level
    }

    return result;
}

// Helper function to print the output
void printLevels(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }
}

// Main function for testing
int main() {
    int arr[] = {10, 5, 15, 3, 7, 12, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> result = binTreeSortedLevels(arr, n);

    cout << "Sorted Level Order Traversal:" << endl;
    printLevels(result);

    return 0;
}
