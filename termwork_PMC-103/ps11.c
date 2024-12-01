#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;
    int alphabets = 0, digits = 0, whitespaces = 0, specialchars = 0, lines = 0;

    // Write to the file
    file = fopen("C:\\users\\abhij\\desktop\\Data.txt", "w");
    if (file == NULL) {
        perror("Unable to open file in write mode");
        return 1;
    }
    fputs("Hello World!\nThis is a test file with 123 numbers.", file);
    fclose(file);

    // Read from the file and count characters
    file = fopen("C:\\users\\abhij\\desktop\\Data.txt", "r");
    if (file == NULL) {
        perror("Unable to open file in read mode");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch))
            alphabets++;
        else if (isdigit(ch))
            digits++;
        else if (isspace(ch)) {
            whitespaces++;
            if (ch == '\n')
                lines++;
        } else
            specialchars++;
    }

    fclose(file);

    printf("Alphabets: %d\nDigits: %d\nWhitespaces: %d\nSpecial Characters: %d\nLines: %d\n",
           alphabets, digits, whitespaces, specialchars, lines + 1);

    return 0;
}
