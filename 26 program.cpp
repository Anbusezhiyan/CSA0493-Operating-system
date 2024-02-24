#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[] = "example.txt";
    char buffer[100];

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }
    fprintf(fp, "Hello, this is a test.\n");
    fclose(fp);
    printf("File '%s' created and written to successfully.\n", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }
    printf("Contents of '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        exit(1);
    }
    fprintf(fp, "This is additional text.\n");
    fclose(fp);
    printf("Text appended to '%s' successfully.\n", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }
    printf("Contents of '%s' after appending:\n", filename);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);

    if (remove(filename) != 0) {
        printf("Error deleting file.\n");
        exit(1);
    }
    printf("File '%s' deleted successfully.\n", filename);

    return 0;
}
