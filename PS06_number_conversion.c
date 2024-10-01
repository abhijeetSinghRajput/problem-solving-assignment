#include <stdio.h>
#include <math.h>

void convert(long long num, char type) {

    int mask, maskSize;
    int size = sizeof(num) * 8;
    const char *prefix;

    switch (type) {
        case 'b': (mask = 0b0001, maskSize = 1, prefix = "0b"); break;
        case 'o': (mask = 0b0111, maskSize = 3, prefix = "0"); break;
        case 'h': (mask = 0b1111, maskSize = 4, prefix = "0x"); break;
        default:  printf("Invalid Type\n"); return;
    }

    printf("%s", prefix);
    int segments = ceil((float)size / maskSize) - 1;
    int val;
    int flag = 1; // help to avoid Leading zeros

    for(int i = segments; i >= 0; --i){
        val = num >> (i * maskSize) & mask;
        if(val != 0) flag = 0;
        if(flag) continue;

        if(val > 9){
            printf("%c", 'a' + val % 10);
        }
        else{
            printf("%d", val);
        }
    }

    printf("\n");
}

int main() {
    long long int decimalNum;
    printf("enter a decimal number: ");
    scanf("%lld", &decimalNum);

    convert(decimalNum, 'h'); 
    convert(decimalNum, 'o'); 
    convert(decimalNum, 'b'); 
    return 0;
}
