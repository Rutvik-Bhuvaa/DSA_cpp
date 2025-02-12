// Binary search algorithm => T(c) = O(log n)

#include<iostream> 
using namespace std; 

int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size -1;

    while(start <= end){
        int mid = end + (start-end)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[6] = {11, 17, 32, 54, 69, 83};
    int size = (sizeof arr/ sizeof arr[0]);
    int target;
    cout << "Enter the value you want to find inside array: ";
    cin >> target;

    int index = binarySearch(arr, size, target);
    if (index != -1) {
        cout << "Target is present at index: " << index << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
    return 0;

}