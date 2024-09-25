#include <stdio.h>
int HCF(int num1, int num2){
    int rem;
    do
    {
        rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    } while (num2 != 0);
    return num1;
}

int LCM(int num1, int num2){
    
    return (num1 * num2) / HCF(num1, num2);
}

int main(){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("LCM: %d\n", LCM(num1, num2));
    printf("HCF: %d\n", HCF(num1, num2));
}