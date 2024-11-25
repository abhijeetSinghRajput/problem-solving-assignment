#include<stdio.h>
#include<math.h>

int isPrime(int i){
    if(i <= 1) return 0;
    if(i <= 3) return 1;
    if(i % 2 == 0 || i % 3 == 0) return 0;

    int sq = sqrt(i); 
    // logn / 6
    for(int j = 5; j <= sq; j += 6){
        if(i % j == 0 || i % (j + 2) == 0){
            return 0;
        } 
    }
    return 1;
}
// constant O(1)
// O(logn)
// O(n)
// O(nlogn)
// O(n^2)
// O(n^3)
// O(n!)
// O(n^n)

// 20
// 20 x 20



int main(){
    int n;
    printf("enter the nth term: ");
    scanf("%d", &n);

    int count = 0;
    for(int i = 1; count<n; i++){
        if(isPrime(i)){
            ++count;
            printf("%d %d\n", count, i);
        }
    }
    return 0;
}