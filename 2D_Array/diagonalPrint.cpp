// Print array diagonally

#include<iostream>
using namespace std;


int main(){

    int matrix[5][4];
    cout << "Enter the value: " << endl;
    
    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            cin >> matrix[i][j];
        }
    }

    int row = 0;
    int col = 0;
    int i,j;

    while(col < 4){
        i=0; j=col;
        while(j >= 0){
            cout << matrix[i][j] << " ";
            i++; 
            j--;
        }
        col++;
    }

    row = 1;

    while(row < 5){
        i=row; j=3;
        while(i < 5){
            cout << matrix[i][j] << " ";
            i++; 
            j--;
        }
        row++;
    }
    return 0;
}