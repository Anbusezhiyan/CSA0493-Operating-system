#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

// Function to calculate total head movements
int calculate_head_movements(int initial_head, int requests[], int total_requests) {
    int head_movements = 0;
    int current_head = initial_head;

    for (int i = 0; i < total_requests; i++) {
        head_movements += abs(current_head - requests[i]);
        current_head = requests[i];
    }

    return head_movements;
}

int main() {
    int initial_head, total_requests;
    int requests[MAX_REQUESTS];

    printf("Enter the initial head position: ");
    scanf("%d", &initial_head);

    printf("Enter the total number of disk requests: ");
    scanf("%d", &total_requests);

    printf("Enter the disk requests: ");
    for (int i = 0; i < total_requests; i++) {
        scanf("%d", &requests[i]);
    }

    int total_head_movements = calculate_head_movements(initial_head, requests, total_requests);

    printf("Total head movements: %d\n", total_head_movements);

    return 0;
}
