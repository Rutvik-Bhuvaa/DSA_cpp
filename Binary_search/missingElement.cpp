// Find the smallest missing element in given array

#include<iostream>
using namespace std;

int smallestMissingElement(int arr[], int size){
    int start = 0;
    int end = size -1;
    int index;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == mid){
            index = mid+1;
            start = mid+1;
        }else{
            index = mid;
            end = mid-1;
        }
    }
    return index;
}

int main(){
    int n;
    cout << "Enter the no.: ";
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = smallestMissingElement(arr, size);
    cout << "Smallest missing element is: " << result;

    return 0;
}