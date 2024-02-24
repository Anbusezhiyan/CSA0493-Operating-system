#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

typedef struct {
    int page;
    int time;
} Frame;

void printFrames(Frame frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i].page == -1) {
            printf("- ");
        } else {
            printf("%d ", frames[i].page);
        }
    }
    printf("\n");
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    Frame frames[MAX_FRAMES];
    int frameCount = 0;
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i].page = -1;
        frames[i].time = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j].page == page) {
                found = 1;
                frames[j].time = i;
                break;
            }
        }
        if (!found) {
            int oldestIndex = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (frames[j].time < frames[oldestIndex].time) {
                    oldestIndex = j;
                }
            }
            frames[oldestIndex].page = page;
            frames[oldestIndex].time = i;
            pageFaults++;
            printf("Page %d -> ", page);
            printFrames(frames, MAX_FRAMES);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
