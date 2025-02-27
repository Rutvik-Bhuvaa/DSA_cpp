#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // here pivot index comes as a return value from partition
        int pi = partition(arr, left, right);
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
}

int main() {
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    quicksort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
