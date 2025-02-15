// subarray with given sum in sorted array

#include<iostream>
using namespace std;

void subarraySum(int arr[], int size, int sum){
    int first = 0;
    int last = size -1;
    
    while(first < last){
        if(arr[first] + arr[last] == sum){
            cout << "From " << first << " to " << last << " position";
            return;
        }else if(arr[first] + arr[last] < sum){
            first++;
        }else{
            last--;
        }
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

    int sum; 
    cout << "Enter the sum: ";
    cin >> sum;

    subarraySum(arr, size, sum);
    return 0; 
}