#include <stdio.h>
#include <math.h>

void convert(long long num, char type) {

    int mask, maskSize;
    int size = sizeof(num) * 8;
    const char *prefix;

    switch (type) {
        case 'b': (mask = 0b0001, maskSize = 1, prefix = "0b "); break;
        case 'o': (mask = 0b0111, maskSize = 3, prefix = "0 "); break;
        case 'h': (mask = 0b1111, maskSize = 4, prefix = "0x "); break;
        default:  printf("Invalid Type\n"); return; // This should never happen due to earlier validation
    }

    printf("%s", prefix);
    int segments = ceil((float)size / maskSize) - 1;
    int val;
    for(int i = segments; i >= 0; --i){
        val = num >> (i * maskSize) & mask;
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
    convert(26939511, 'h'); // 0x19b1077
    convert(26939511, 'o'); // 0146610167
    convert(26939511, 'b'); // 0b1100110110001000001110111
    return 0;
}
