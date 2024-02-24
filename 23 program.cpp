#include <stdio.h>
#include <stdlib.h>

void SCAN(int arr[], int head, int direction, int size, int max_cylinder) {
    int total_seek = 0;
    int curr_track = head;
    int visited[max_cylinder + 1];

    for (int i = 0; i <= max_cylinder; i++) {
        visited[i] = 0;
    }

    printf("Sequence of tracks visited:\n");
    while (1) {
        printf("%d ", curr_track);
        visited[curr_track] = 1;

        int all_visited = 1;
        for (int i = 0; i <= max_cylinder; i++) {
            if (visited[i] == 0) {
                all_visited = 0;
                break;
            }
        }
        if (all_visited) {
            break;
        }

        if (direction == 1) {
            if (curr_track == max_cylinder) {
                direction = -1;
                continue;
            }
            curr_track++;
        } else { 
            if (curr_track == 0) {
                direction = 1;
                continue;
            }
            curr_track--;
        }

        for (int i = 0; i < size; i++) {
            if (arr[i] == curr_track) {
                total_seek += abs(curr_track - head);
                head = curr_track;
                break;
            }
        }
    }

    printf("\nTotal seek time: %d\n", total_seek);
}

int main() {
    int n, head, max_cylinder, direction;
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

    printf("Enter the initial direction (1 for right, -1 for left): ");
    scanf("%d", &direction);

    SCAN(requests, head, direction, n, max_cylinder);

    return 0;
}
