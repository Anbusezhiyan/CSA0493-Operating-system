#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 100 // Assuming each block can hold 100 characters of data

// Structure to represent a block on the disk
typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block *next_block;
} Block;

// Structure to represent a file
typedef struct File {
    Block *first_block;
    Block *last_block;
    struct File *next_file; // Added next_file pointer to support multiple files in the directory
} File;

// Structure to represent the directory
typedef struct Directory {
    File *files;
    int total_files;
} Directory;

Directory directory; // Directory to hold files

// Function to initialize the directory
void initialize_directory() {
    directory.files = NULL;
    directory.total_files = 0;
}

// Function to create a new file
void create_file() {
    File *new_file = (File *)malloc(sizeof(File));
    new_file->first_block = NULL;
    new_file->last_block = NULL;
    new_file->next_file = NULL; // Initialize next_file pointer

    if (directory.files == NULL) {
        directory.files = new_file;
    } else {
        File *temp = directory.files;
        while (temp->next_file != NULL) {
            temp = temp->next_file;
        }
        temp->next_file = new_file;
    }
    directory.total_files++;
    printf("File created successfully!\n");
}

// Function to add a new block to a file
void add_block(File *file, char *data) {
    Block *new_block = (Block *)malloc(sizeof(Block));
    sprintf(new_block->data, "%s", data);
    new_block->next_block = NULL;

    if (file->first_block == NULL) {
        file->first_block = new_block;
        file->last_block = new_block;
    } else {
        file->last_block->next_block = new_block;
        file->last_block = new_block;
    }
    printf("Block added to file successfully!\n");
}

// Function to read the entire file
void read_file(File *file) {
    printf("Reading file:\n");
    Block *current_block = file->first_block;
    while (current_block != NULL) {
        printf("%s", current_block->data);
        current_block = current_block->next_block;
    }
    printf("\n");
}

int main() {
    // Initialize the directory
    initialize_directory();

    // Create a new file
    create_file();

    // Add some blocks to the file
    add_block(directory.files, "Data of block 1\n");
    add_block(directory.files, "Data of block 2\n");
    add_block(directory.files, "Data of block 3\n");

    // Read the entire file
    read_file(directory.files);

    return 0;
}

