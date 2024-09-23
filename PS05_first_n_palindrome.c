#include <stdio.h>
int isPalindrome(int num)
{
    int rev = 0;
    int temp = num;
    while (temp)
    {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }
    return rev == num;
}

int main()
{
    int n;
    printf("Enter the n: ");
    scanf("%d", &n);

    int i, count;
    i = count = 1;
    while (count <= n)
    {
        if (isPalindrome(i))
        {
            printf("%3d %d\n", count++, i);
        }
        i++;
    }

    return 0;
}