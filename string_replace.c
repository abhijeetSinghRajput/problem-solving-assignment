#include <stdio.h>
#include <string.h>
size_t findAll(char *, char *, int[]);
void concat(char *, char *, int, int);

int main()
{
    char *str = "ganga gagan ganda gagan";
    char *pattern = "gagan";
    char *replace = "Abhijeet singh rajput";
    int arr[100];
    char s[10];
    int i = 0;

    int arr_len = findAll(str, pattern, arr);
    // newstr_len = str len - (all matched word len ) + (all replace word len)
    int newstr_len = strlen(str) - (arr_len * strlen(pattern)) + (arr_len * strlen(replace));
    char newstr[newstr_len + 1];
    newstr[0] = '\0';
    
    for (int i = 0, j = 0; i < arr_len; ++i)
    {
        concat(newstr, str, j, arr[i]);
        concat(newstr, replace, 0, strlen(replace));
        j = arr[i] + strlen(pattern);
    }
    puts(newstr);
    return 0;
}

size_t findAll(char *str, char *pattern, int arr[])
{
    int str_len = strlen(str);
    int pattern_len = strlen(pattern);
    size_t arr_len = 0;
    for (int i = 0; i <= str_len - pattern_len; ++i)
    {
        int j = 0;
        while (pattern[j] == str[i + j])
        {
            j++;
            if (pattern[j] == '\0')
            {
                arr[arr_len] = i;
                arr_len++;
                break;
            }
        }
    }
    return arr_len;
}

void concat(char *dest, char *src, int start, int end)
{
    int dest_len = strlen(dest);
    int i, j = 0;
    for (i = start; i < end; ++i, ++j)
    {
        dest[dest_len + j] = src[i];
    }
    dest[dest_len + j] = '\0';
}