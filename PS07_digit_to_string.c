#include<stdio.h>
char *toString(int digit){
    switch (digit)
    {
        case 0: return "Zero";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
    
        default: return "";
    }
}

void printWord(int num){
    if(num == 0) return;
    printWord(num / 10);
    printf("%s ", toString(num % 10));
}

int main(){
    int num;
    printf("enter a number: ");
    scanf("%d", &num);

    printWord(num);

    return 0;
}