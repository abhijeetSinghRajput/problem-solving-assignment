#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <substring>\n", argv[0]);
        return 1;
    }

    FILE *file;
    char *filename = argv[1];
    char *substring = argv[2];
    char line[256];
    int count = 0;

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return 1;
    }

    // Search for the substring
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, substring) != NULL)
            count++;
    }

    fclose(file);

    printf("The substring '%s' occurs %d times in the file '%s'.\n",
           substring, count, filename);

    return 0;
}
