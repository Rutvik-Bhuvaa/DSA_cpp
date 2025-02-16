#include<iostream>
using namespace std;

void print2DArray(int arr[][3], int row, int col){

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int row = 3;
    int col = 3;
    int arr[3][3];

    cout << "Enter the no in 2D array: " << endl;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }


    print2DArray(arr, row, col);
    return 0;
}