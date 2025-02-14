// Search in a rotated array

#include<iostream>
using namespace std;

int searchInRotatedArray(int arr[], int size, int target){
    int start = 0;
    int end = size -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[start] <= arr[mid]){
            if(target >= arr[start] && target < arr[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }else{
            if(target > arr[mid] && target <= arr[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        
    }
    return -1;
}

int main(){
    int n; 
    cout << "Enter the number: ";
    cin >> n;

    int arr[n];
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the value you want to find: ";
    cin >> target;

    int result = searchInRotatedArray(arr, size, target);
    cout << target << " is found at index " << result;

    return 0;
}