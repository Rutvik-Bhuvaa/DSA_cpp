// leetcode problem no. 198
// TC = 2^N

#include<iostream>
#include<algorithm>
using namespace std;

void rob(int arr[], int size, int &sum, int total, int index){


    if(index >= size){
        sum = max(sum, total);
        return;
    }

    rob(arr, size, sum, total, index+1);
    rob(arr, size, sum, total+arr[index], index+2);

}

int main(){
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the numbers: " << endl;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    } 

    int sum = 0;
    int total = 0;
    int index = 0;
    rob(arr, n, sum, total, index);
    cout << "Maximum amount robber can steal is: "<< sum;
    return 0;
}