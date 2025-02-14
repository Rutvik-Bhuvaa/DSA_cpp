#include<iostream>
using namespace std; 

int findPages(int arr[], int size, int student){


    if(student > size){
        return -1;
    }

    int start = arr[0];
    int end = 0;
    int ans = -1;

    for(int i=0; i<size; i++){
        end += arr[i];
        if(start < arr[i]){
            start = arr[i];
        }
    }

    while(start <= end){
        int mid = start + (end-start)/2;
        int count = 1;
        int allocatedPages = 0;

        for(int i=0; i<size; i++){
            if(allocatedPages + arr[i] > mid){
                count++;
                allocatedPages = arr[i];
            }else{
                allocatedPages += arr[i];
            }
        }

        if(count <= student){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
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

    int student;
    cout << "Enter the no of students: ";
    cin >> student;


    int result = findPages(arr, size, student);
    cout << "Minimum no of pages are " << result;
    return 0;
}