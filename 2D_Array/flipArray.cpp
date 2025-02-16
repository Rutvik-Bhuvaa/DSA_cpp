#include<iostream>
using namespace std;

void flipArray(int arr[][4], int row, int col){

    for(int i=0; i<row/2; i++){
        for(int j=0; j<col; j++){
            swap(arr[i][j] ,arr[row-1-i][j]);
        }
    }


    cout << "Fliped matrix 180 degree: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int row = 4;
    int col = 4;
    int arr[4][4];

    cout << "Enter the no in 2D array: " << endl;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }


    flipArray(arr, row, col);
    return 0;
}