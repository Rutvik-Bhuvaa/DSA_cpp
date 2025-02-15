// container with most water

#include<iostream>
using namespace std;

int maxWater(int arr[], int size){
    int sum = 0;
    int first = 0;
    int last = size-1;
    int length, breadth;

    while(first < last){
        breadth = last - first;
        if(arr[first] > arr[last]){
            length = arr[last--];
        }else{
            length = arr[first++];
        }

        if(sum < length * breadth){
            sum = length * breadth;
        }
    }
    return sum;
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

    int mostWater = maxWater(arr, size);
    cout << "Max water is " << mostWater << " unit";
    return 0;
}