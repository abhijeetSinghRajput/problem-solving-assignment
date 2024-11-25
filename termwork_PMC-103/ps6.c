#include<stdio.h>
int binarySearch(int arr[], int low, int high, int key){
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == key) return mid;

    if(key < arr[mid]){
        return binarySearch(arr, low, mid-1, key);
    }
    else{
        return binarySearch(arr, mid+1, high, key);
    }
}

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
void printArr(int arr[], int n){
    for(int i = 0; i<n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n, key;
    printf("Enter the size of arr: ");
    scanf("%d", &n);
    int arr[n];
    inputArr(arr, n);
    printf("Enter the key: ");
    scanf("%d", &key);
    
    sort(arr, n);
    printArr(arr, n);
    int result = binarySearch(arr, 0, n, key);
    if(result != -1){
        printf("key found at %d\n", result);
    }
    else{
        printf("key not found\n");
    }
    return 0;
}