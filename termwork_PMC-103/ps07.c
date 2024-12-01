#include<stdio.h>
#include<string.h>

int main(){
    int lastIndex[256];
    for(int i = 0; i<256; ++i){
        lastIndex[i] = -1;
    }

    char str[100];
    printf("Enter a string: ");
    gets(str);
    int maxLen = 0;
    int i = 0;
    for(int j = 0; j<strlen(str); ++j){
        if(lastIndex[str[j]] >= i){
            i = lastIndex[str[j]] + 1;
        }
        lastIndex[str[j]] = j;
        int len = j - i + 1;
        if(len > maxLen){
            maxLen = len;
        }
    }

    printf("Longest Substring Without Repeating Length: %d", maxLen);
    return 0;
}