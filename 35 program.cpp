#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100
#define BLOCK_SIZE 100 // Assuming each block can hold 100 characters of data

// Structure to represent a block of the file
typedef struct {
    char data[BLOCK_SIZE];
} Block;

// Structure to represent the index block
typedef struct {
    Block *blocks[MAX_BLOCKS];
    int total_blocks;
} IndexBlock;

IndexBlock index_block; // Index block to hold pointers to file blocks

// Function to initialize the index block
void initialize_index_block() {
    index_block.total_blocks = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        index_block.blocks[i] = NULL;
    }
}

// Function to add a new block to the file
void add_block(char *data) {
    if (index_block.total_blocks < MAX_BLOCKS) {
        Block *new_block = (Block *)malloc(sizeof(Block));
        sprintf(new_block->data, "%s", data);
        index_block.blocks[index_block.total_blocks] = new_block;
        index_block.total_blocks++;
        printf("Block added successfully!\n");
    } else {
        printf("File is full. Cannot add more blocks.\n");
    }
}

// Function to read the entire file
void read_file() {
    printf("Reading the entire file:\n");
    for (int i = 0; i < index_block.total_blocks; i++) {
        printf("Block %d: %s\n", i + 1, index_block.blocks[i]->data);
    }
}

int main() {
    // Initialize the index block
    initialize_index_block();

    // Add some blocks to the file
    add_block("Data of block 1");
    add_block("Data of block 2");
    add_block("Data of block 3");

    // Read the entire file
    read_file();

    return 0;
}
