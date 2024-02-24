#include <stdio.h>

#define MAX_FRAMES 3

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[MAX_FRAMES];
    int frameCount = 0;
    int pageFaults = 0;
    int nextFrame = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frames[nextFrame] = page;
            nextFrame = (nextFrame + 1) % MAX_FRAMES;
            pageFaults++;
            printf("Page %d -> ", page);
            printFrames(frames, MAX_FRAMES);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
