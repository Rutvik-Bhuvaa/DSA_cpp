// pick index in mountain array

#include<iostream>
using namespace std;

int peakIndexInMountainArray(int arr[], int size){
    int start = 0;
    int end = size -1;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}


int main(){
    int arr[4] = {0, 10, 5, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int result = peakIndexInMountainArray(arr, size);
    cout << "Peak index in mountain array is at "<< result << " index";
    return 0;
}