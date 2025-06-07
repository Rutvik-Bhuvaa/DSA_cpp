// leetcode problem no. 213
// TC = 

#include<iostream>
#include<algorithm>
using namespace std;

void rob(int arr[], int index, int size, int &sum, int total){
    if(index >= size){
        sum = max(sum, total);
        return;
    }

    rob(arr, index+1, size, sum, total);
    rob(arr, index+2, size, sum, total+arr[index]);
}

int main(){
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    int total = 0;

    rob(arr, 1, n, sum, total);
    rob(arr, 0, n-1, sum, total);
    cout << "Maximum a robber can steal is: " << sum;
    return 0;
}