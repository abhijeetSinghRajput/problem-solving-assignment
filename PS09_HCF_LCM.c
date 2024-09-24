#include <stdio.h>
int LCM(int num1, int num2){
    int min = (num1 < num2)? num1 : num2;
    for(int i = 2; i<=min; ++i){
        if(num1 % i == 0 && num2 % i == 0){
            return i;
        }
    }
    return 1;
}

int HCF(int num1, int num2){
    int max = (num1 > num2)? num1 : num2;
    for(int i = max; i >= 2; --i){
        if(num1 % i == 0 && num2 % i == 0){
            return i;
        }
    }
    return 1;
}

int main(){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("LCM: %d\n", LCM(num1, num2));
    printf("HCF: %d\n", HCF(num1, num2));
}