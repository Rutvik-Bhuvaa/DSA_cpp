// Insertion sort  : T(c) = O(n^2)


#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=i; j>=0; j--){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }else{
                break;
            }
        }
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[5] = {9,8,7,6,5};
    int size = (sizeof arr/sizeof arr[0]);

    insertionSort(arr, size);
    cout << "Sorted array is: ";
    printArray(arr, size);
    return 0;
}