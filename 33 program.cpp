#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PHYSICAL_MEMORY_SIZE 3
#define VIRTUAL_MEMORY_SIZE 10

int physical_memory[PHYSICAL_MEMORY_SIZE];
int page_references[VIRTUAL_MEMORY_SIZE] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};

bool is_page_in_memory(int page) {
    for (int i = 0; i < PHYSICAL_MEMORY_SIZE; i++) {
        if (physical_memory[i] == page) {
            return true;
        }
    }
    return false;
}

int find_optimal_page(int index) {
    int farthest_index = -1;
    int farthest_page = -1;
    for (int i = 0; i < PHYSICAL_MEMORY_SIZE; i++) {
        int j;
        for (j = index; j < VIRTUAL_MEMORY_SIZE; j++) {
            if (physical_memory[i] == page_references[j]) {
                if (j > farthest_index) {
                    farthest_index = j;
                    farthest_page = i;
                }
                break;
            }
        }
        if (j == VIRTUAL_MEMORY_SIZE) {
            return i;
        }
    }
    return farthest_page;
}

void print_physical_memory() {
    printf("Physical Memory: ");
    for (int i = 0; i < PHYSICAL_MEMORY_SIZE; i++) {
        if (physical_memory[i] == -1) {
            printf("Empty ");
        } else {
            printf("%d ", physical_memory[i]);
        }
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < PHYSICAL_MEMORY_SIZE; i++) {
        physical_memory[i] = -1;
    }

    int page_faults = 0;
    for (int i = 0; i < VIRTUAL_MEMORY_SIZE; i++) {
        printf("Page Reference: %d\n", page_references[i]);
        if (!is_page_in_memory(page_references[i])) {
            int page_to_replace = find_optimal_page(i);
            physical_memory[page_to_replace] = page_references[i];
            page_faults++;
            print_physical_memory();
        }
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
