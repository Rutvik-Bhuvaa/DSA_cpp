// Search insert position

#include<iostream>
using namespace std;

int searchInsert(int arr[], int size, int target){
    int start = 0;
    int end = size-1;
    int index;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            start = mid+1;
            index = mid+1;
        }else{
            end = mid-1;
            index = mid;
        }

    }
    return index;
}

int main(){

    int arr[4] = {1,3,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    cout << "Enter the insert position to search: ";
    cin >> target;

    int result = searchInsert(arr, size, target);
    cout << "Position is at " << result << " index";
    return 0;
}