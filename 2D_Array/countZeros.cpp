// Count total no of zeros in sorted matrix

#include<iostream>
using namespace std;

int main(){

    int row = 3;
    int col = 3;
    int arr[3][3];
    cout << "Enter the no: "<< endl;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    int count = 0;
    int i = 0;
    int j = col-1;
    
    while(i < row && j >= 0){
        while(j>=0 && arr[i][j] == 1){
            j--;
        }

        count += j+1;
        i++;
    }

    cout << "Total no of zeros is: " << count;
    return 0;
}