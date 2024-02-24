#include <stdio.h>
#include <stdlib.h>

void CSCAN(int arr[], int head, int size, int max_cylinder) {
    int total_seek = 0;
    int curr_track = head;
    int visited[max_cylinder + 1];

    // Initialize visited array
    for (int i = 0; i <= max_cylinder; i++) {
        visited[i] = 0;
    }

    // Simulate C-SCAN algorithm
    printf("Sequence of tracks visited:\n");
    int start = 0;
    while (start <= max_cylinder) {
        if (curr_track <= max_cylinder) {
            for (int i = start; i < size; i++) {
                if (arr[i] == curr_track) {
                    total_seek += abs(curr_track - head);
                    head = curr_track;
                    printf("%d ", curr_track);
                    visited[curr_track] = 1;
                    break;
                }
            }
            curr_track++;
        } else {
            curr_track = 0;
        }
        start++;
    }

    printf("\nTotal seek time: %d\n", total_seek);
}

int main() {
    int n, head, max_cylinder;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &head);

    printf("Enter the maximum cylinder size: ");
    scanf("%d", &max_cylinder);

    CSCAN(requests, head, n, max_cylinder);

    return 0;
}
