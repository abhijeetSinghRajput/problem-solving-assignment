#include<stdio.h>

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
    int r1, c1, r2, c2;
    scanf("%d %d", &r1, &c1);
    scanf("%d %d", &r2, &c2);
    if(c1 != r2){
        printf("invalid order");
        return 0;
    }
    int mat1[r1][c1];
    int mat2[r2][c2];

    inputMatrix(r1, c1, mat1);
    inputMatrix(r2, c2, mat2);

    printf("Matrix 1: \n");
    printMatrix(r1, c1, mat1);

    printf("Matrix 2: \n");
    printMatrix(r2, c2, mat2);

    // multiplication of matrix
    int result[r1][c2];
    for(int i = 0; i<r1; ++i){
        for(int j = 0; j<c2; ++j){
            result[i][j] = 0;
            for(int k = 0; k<r2; ++k){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Result: \n");
    printMatrix(r1, c2, result);

    int transpose[c2][r1];
    for(int i = 0; i<c2; ++i){
        for(int j = 0; j<r1; ++j){
            transpose[i][j] = result[j][i];
        }
    }

    printf("Transpose: \n");
    printMatrix(r1, c2, transpose);

    return 0;
}