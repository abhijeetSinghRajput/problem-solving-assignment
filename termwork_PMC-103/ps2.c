#include<stdio.h>

int isIdentity(int row, int col, int matrix[][col]){
    if(row != col) return 0;
    for(int i = 0; i<row; ++i){
        for(int j = 0; j<col; ++j){
            if(i == j && matrix[i][j] != 1){
                return 0;
            }
            else if(i != j && matrix[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

void inputMatrix(int row, int col, int matrix[][col]){
    for(int i = 0; i<row; ++i){
        for(int j = 0; j<col; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int row, int col, int matrix[][col]){
    for(int i = 0; i<row; ++i){
        for(int j = 0; j<col; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int row, col;
    scanf("%d %d", &row, &col);
    int matrix[row][col];
    inputMatrix(row, col, matrix);
    printMatrix(row, col, matrix);
    printf(isIdentity(row, col, matrix)? "Identity" : "Non Identity");
    return 0;
}