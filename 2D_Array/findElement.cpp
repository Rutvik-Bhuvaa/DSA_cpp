// Find any element in 2D array

#include<iostream>
using namespace std;

void findElement(int matrix[3][3], int row, int col, int key){

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] == key){
                cout << "key is found at index: " << (i*3) + j;
                return;
            }
        }
    }
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

    int key;
    cout << "Enter the key you want to find inside 2D-Array: ";
    cin >> key;

    findElement(matrix, row, col, key);
    return 0;
}