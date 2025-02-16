// Find any element in 2D array

#include<iostream>
using namespace std;

int sumColMajor(int matrix[3][3], int row, int col){
    int sum = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            sum += matrix[j][i];
        }
        cout <<"Sum of till col " << i << " " << sum << endl;
    }

    return sum;
}

int main(){

    int row = 3;
    int col = 3;

    int matrix[3][3];
    cout << "Enter the no in 2D Array: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> matrix[i][j];
        }
    }

    int sum = sumColMajor(matrix, row, col);
    cout << "Total sum is: " << sum;
    return 0;
}