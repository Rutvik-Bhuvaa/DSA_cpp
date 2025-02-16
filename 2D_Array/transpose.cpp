#include<iostream>
using namespace std;

void transpose(int arr[][3], int row, int col){

    for(int i=0; i<row; i++){
        for(int j=i+1; j<col; j++){
            swap(arr[i][j] ,arr[j][i]);
        }
    }


    cout << "Transpose of the matrix is: " << endl;
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


    transpose(arr, row, col);
    return 0;
}