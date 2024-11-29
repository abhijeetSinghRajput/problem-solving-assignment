#include<stdio.h>
void sort(int arr[], int n){
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
void print(int arr[], int n){
    for(int i = 0; i<n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("enter the size of arr: ");
    scanf("%d", &n);
    int arr[n];
    inputArr(arr, n);
    sort(arr, n);
    int result[n], i = 0, j = n-1, k = 0;
    while(i <= j){
        result[k++] = arr[i++];
        result[k++] = arr[j--];
    }
    print(result, n);
}