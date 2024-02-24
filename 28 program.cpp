#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *pattern;
    int line_number = 0;


    if (argc != 3) {
        fprintf(stderr, "Usage: %s pattern filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pattern = argv[1];
    char *filename = argv[2];

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line_number++;
        if (strstr(line, pattern) != NULL) {
            printf("%s:%d: %s", filename, line_number, line);
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}
