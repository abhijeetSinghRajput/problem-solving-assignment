#include<stdio.h>
void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; ++i){
        int minIndex = i;
        int minValue = arr[i];
        for(int j = i + 1; j<n; ++j){
            if(arr[j] < minValue){
                minValue = arr[j];
                minIndex = j;
            }
        }

        // swap the current value with min
        if(minIndex != i){
            arr[i] ^= arr[minIndex];
            arr[minIndex] ^= arr[i];
            arr[i] ^= arr[minIndex];
        }
    }
}
int inputArr(int arr[], int n){
    for(int i = 0; i<n; ++i){
        printf("enter the element of arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void printArr(int arr[], int n){
    for(int i = 0; i<n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the size of arr: ");
    scanf("%d", &n);
    int arr[n];
    inputArr(arr, n);
    selectionSort(arr, n);
    printArr(arr, n);
    return 0;
}