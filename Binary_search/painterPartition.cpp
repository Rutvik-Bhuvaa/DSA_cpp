
#include<iostream>
using namespace std;

int minTime(int arr[], int size, int painter){

    int ans = -1;
    int start = arr[0];
    int end = 0;

    for(int i=0; i<size; i++){
        end += arr[i];
        if(start < arr[i]){
            start = arr[i];
        }
    }

    while(start <= end){
        int mid = start + (end-start)/2;
        int count = 1;
        int totalTime = 0;

        for(int i=0; i<size; i++){
            if(totalTime + arr[i] > mid){
                count++;
                totalTime = arr[i];
            }else{
                totalTime += arr[i];
            }
        }

        if(count <= painter){
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
    cout << "Enter the no of boards for painting: ";
    cin >> n;

    int arr[n];
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int painter;
    cout << "Enter the no of painters for painting: ";
    cin >> painter;

    int result = minTime(arr, size, painter);
    cout << "Total time taken is " << result;
    return 0;
}