#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define MAX_TRACKS 1000

// Function to sort the requests in ascending order
void sort_requests(int requests[], int total_requests) {
    for (int i = 0; i < total_requests - 1; i++) {
        for (int j = 0; j < total_requests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                // Swap requests
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}

// Function to simulate SCAN disk scheduling algorithm
int simulate_SCAN(int initial_head, int requests[], int total_requests) {
    sort_requests(requests, total_requests);

    int total_head_movements = 0;
    int current_head = initial_head;
    int direction = 1; // 1 for moving towards higher tracks, -1 for moving towards lower tracks

    // Find the index of the first request greater than or equal to the initial head
    int start_index = 0;
    while (start_index < total_requests && requests[start_index] < initial_head) {
        start_index++;
    }

    // Move in the current direction until reaching the end
    for (int i = start_index; i < total_requests && i >= 0; i += direction) {
        total_head_movements += abs(current_head - requests[i]);
        current_head = requests[i];
    }

    // Move in the opposite direction until reaching the other end
    direction *= -1; // Reverse direction
    for (int i = start_index - direction; i < total_requests && i >= 0; i += direction) {
        total_head_movements += abs(current_head - requests[i]);
        current_head = requests[i];
    }

    return total_head_movements;
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

    int total_head_movements = simulate_SCAN(initial_head, requests, total_requests);

    printf("Total head movements: %d\n", total_head_movements);

    return 0;
}
