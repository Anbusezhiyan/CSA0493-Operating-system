#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    struct stat file_stat;

    // Get file information
    if (stat(filename, &file_stat) == -1) {
        perror("Error getting file information");
        exit(EXIT_FAILURE);
    }

    // Print file permissions
    printf("File: %s\n", filename);
    printf("Owner permissions: %c%c%c\n",
           (file_stat.st_mode & S_IRUSR) ? 'r' : '-',
           (file_stat.st_mode & S_IWUSR) ? 'w' : '-',
           (file_stat.st_mode & S_IXUSR) ? 'x' : '-');
    printf("Group permissions: %c%c%c\n",
           (file_stat.st_mode & S_IRGRP) ? 'r' : '-',
           (file_stat.st_mode & S_IWGRP) ? 'w' : '-',
           (file_stat.st_mode & S_IXGRP) ? 'x' : '-');
    printf("Others permissions: %c%c%c\n",
           (file_stat.st_mode & S_IROTH) ? 'r' : '-',
           (file_stat.st_mode & S_IWOTH) ? 'w' : '-',
           (file_stat.st_mode & S_IXOTH) ? 'x' : '-');

    // Modify file permissions
    if (chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1) {
        perror("Error changing file permissions");
        exit(EXIT_FAILURE);
    }

    printf("File permissions modified.\n");

    return 0;
}
