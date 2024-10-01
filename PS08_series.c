#include <stdio.h>
#include <math.h>


// s += 1 + 2^2/2! + ... n^n/n! 
// s += 1 + 2^1/2! + ... n^n-1/n! 
// s += 1 - 2! + 3! - 4! ...

double series1(int i, int fact){
    return pow(i, i)/fact;
}
double series2(int i, int fact){
    return pow(i, i-1)/fact;
}
double series3(int i, int fact){
    return (i & 1)? fact : -fact;
}

double accumulat(int n, double (*callback)(int, int)){
    double sum = 0;
    int fact = 1;
    for(int i = 1; i<= n; ++i){
        fact *= i;
        sum += callback(i, fact);
    }
    return sum;
}


int main(){
    int n;
    printf("enter the nth term: ");
    scanf("%d", &n);

    printf("Series 1: %lf\n", accumulat(n, series1));
    printf("Series 2: %lf\n", accumulat(n, series2));
    printf("Series 3: %lf\n", accumulat(n, series3));

    return 0;
}