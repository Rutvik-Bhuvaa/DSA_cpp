// Remove duplicate element from sorted array

#include<iostream>
using namespace std;

int removeDuplicates(int arr[], int size){
    int note = 0;
    int index = 0;

    for(int i=0; i<size; i++){
        if(arr[i] != note){
            arr[index] = arr[i];
            note = arr[i];
            index++;
        }
    }

    return index;
}

void printArray(int arr[], int index){
    for(int i=0; i<index; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the no: ";
    cin >> n;

    int arr[n];
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int index = removeDuplicates(arr, size);
    printArray(arr, index);
}