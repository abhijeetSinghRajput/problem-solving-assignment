#include <stdio.h>
int main(){
    int n;
    printf("Enter the nth Term: ");
    scanf("%d", &n);
    
    // =============== pattern 1
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<= n - i; ++j){
            printf("  ");
        }
        for(int j = 1; j<=i; ++j){
            printf("%d ", j);
        }
        for(int j = i - 1; j >= 1; --j){
            printf("%d ", j);
        }
        printf("\n");
    }
    for(int i = 2; i<=n; ++i){
        for(int j = 1; j < i; ++j){
            printf("  ");
        }
        for(int j = 1; j<=n + 1 - i; ++j){
            printf("%d ", j);
        }
        for(int j = n - i; j >= 1; --j){
            printf("%d ", j);
        }
        printf("\n");
    }
    

    // =============== pattern 2
    printf("\n\n");
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<= n - i; ++j){
            printf("  ");
        }
        for(int j = n; j > n - i; j--){
            printf("%c ", j + 'A' - 1);
        }
        for(int j = n+2-i; j<=n; ++j){
            printf("%c ", j + 'A' - 1);
        }
        printf("\n");
    }
    for(int i = 2; i<=n; ++i){
        for(int j = 1; j< i; ++j){
            printf("  ");
        }
        for(int j = n; j >= i; j--){
            printf("%c ", j + 'A' - 1);
        }
        for(int j = i + 1; j<=n; ++j){
            printf("%c ", j + 'A' - 1);
        }
        printf("\n");
    }
    return 0;
}
