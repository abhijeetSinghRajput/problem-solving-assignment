#include <stdio.h>

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

struct Pair{
    int first, second;
} typedef Pair;

void insert(Pair freqArr[], int *n, int value){
    // increase the frequency of existing element
    for(int i = 0; i<n; ++i){
        if(freqArr[i].first == value){
            freqArr[i].second++;
            return;
        }
    }

    // add a new element
    freqArr[*n].first = value;
    freqArr[*n].second = 1;
    (*n)++;
}
int main() {
    int arr[] = {2, 3, 4, 5, 4, 3, 1, 7, 8, 9, 8, 5, 1, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    Pair freqArr[n];
    int size = 0;

    for(int i = 0; i<n; ++i){
        insert(freqArr, &size, arr[i]);
    }

    printf("\nUnique numbers are: ");
    for(int i = 0; i<size; ++i){
        if(freqArr[i].second == 1){
            printf("%d ", freqArr[i].first);
        }
    }

    printf("\nDuplicate numbers are: ");
    for(int i = 0; i<size; ++i){
        if(freqArr[i].second > 1){
            printf("%d ", freqArr[i].first);
        }
    }

    printf("\nOccurrence of each numbers are:\n");
    for(int i = 0; i<size; ++i){
        printf("%d : %d\n", freqArr[i].first, freqArr[i].second);
    }
    
    return 0;
}
