#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50] = {0}; // Initialize array elements to 0
    int p, i, st, len, j, c, a;

    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

    do {
        printf("Enter index starting block and length: ");
        scanf("%d %d", &st, &len);

        for (j = st; j < st + len; j++) {
            if (f[j] == 0) {
                f[j] = 1;
                printf("%d-------->%d\n", j, f[j]);
            } else {
                printf("%d Block is already allocated \n", j);
                break; // Exit the loop if block is already allocated
            }
        }

        printf("Do you want to enter more file (Yes - 1 / No - 0): ");
        scanf("%d", &c);
    } while (c == 1);

    return 0;
}
