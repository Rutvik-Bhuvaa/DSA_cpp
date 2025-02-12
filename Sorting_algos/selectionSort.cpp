// Selection sort  : T(c) = O(n^2)


#include<iostream>
using namespace std;

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[5] = {4, 1, 3, 9, 7};
    int size = (sizeof arr/sizeof arr[0]);
    
    selectionSort(arr, size);
    cout << "Sorted array is: ";
    printArray(arr, size);
    return 0;
}