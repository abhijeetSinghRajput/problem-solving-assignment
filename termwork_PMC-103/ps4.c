#include <stdio.h>

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 4, 5, 4, 3, 1, 7, 8, 9, 8, 5, 1, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int aux[n];
    for(int i = 0; i<n; ++i){
        aux[i] = 0;
    }
    printArr(aux, n);
    return 0;
}
