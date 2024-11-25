#include<stdio.h>
int main(){
    int n = 6;
    int i = 2, j = 4, sum = 0;
    while(n--){
        printf("%d + ", i);
        sum += i;
        i += j;
        j += 2;
    }
    printf("\b\b = %d", sum);
    return 0;
}