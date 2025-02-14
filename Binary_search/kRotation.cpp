// find K rotation

#include<iostream>
using namespace std;

int findKRotation(int arr[], int size){
    int start = 0;
    int end = size -1;
    int pivot = arr[0];
    int index;

    while(start <= end){
        int mid = end + (start-end)/2;

        if(arr[mid] > pivot){
            index = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return (index+1)%size;
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int size = sizeof(arr)/sizeof(arr[0]);

    int result = findKRotation(arr, size);
    cout << "Array is rotated " << result << " times";

    return 0;
}