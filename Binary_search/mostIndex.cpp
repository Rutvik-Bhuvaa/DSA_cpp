// Left and Right most index in given array

#include<iostream>
using namespace std;

pair<int, int> indexes(int arr[], int size, int target){
    int start = 0;
    int end = size -1;
    int leftIndex = -1;
    int rightIndex = -1;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            leftIndex = mid;
            end = mid-1;
        }else if(arr[mid] > target){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    start = 0;
    end = size -1;

    while(start <= end){
        int mid = start + (end - start)/2;

         if(arr[mid] == target){
            rightIndex = mid;
            start = mid+1;
        }else if(arr[mid] > target){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return {leftIndex, rightIndex};
}

int main(){
    int arr[6] = {1, 2, 2, 3, 4, 5};
    int size = (sizeof arr/sizeof arr[0]);
    int target;
    cout << "Enter the value you want to find: ";
    cin >> target;

    pair<int, int> result = indexes(arr, size, target);

    cout << "Leftmost index: " << result.first << endl;
    cout << "Rightmost index: " << result.second << endl;
    
    return 0;
}