#include<iostream>
#include<algorithm>
using namespace std;

int aggressiveCows(int arr[], int size, int cows){

    sort(arr, arr+size);

    int start = 1;
    int minElement = arr[0];
    int maxElement = arr[size-1];
    int end = maxElement - minElement;
    int ans = 0;

    while(start <= end){
        int mid = end + (start-end)/2;
        int count = 1;
        int lastPosition = arr[0];
        for(int i=0; i<size; i++){
            if(arr[i] - lastPosition >= mid){
                count++;
                lastPosition = arr[i];
            }

            if(count == cows){
                break;
            }
        }

        if(count == cows){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the no of stalls: ";
    cin >> n;

    int arr[n];
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int cows; 
    cout << "Enter the no of aggressive cows: ";
    cin >> cows;

    int result = aggressiveCows(arr, size, cows);
    cout << "Minimum distance is: " << result;
    return 0;
}