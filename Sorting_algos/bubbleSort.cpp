#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<(size-1)-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
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
    int arr[5] = {5,4,3,2,1};
    int size = (sizeof arr/sizeof arr[0]);

    bubbleSort(arr, size);
    cout << "Sorted array is: ";
    printArray(arr, size);
    return 0;
}