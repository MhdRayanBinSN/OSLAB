#include <stdio.h>

int main() {
    int bsize[10], psize[10], allocation[10];
    int bno, pno, i, j;

    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each block: ");
    for (i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the size of each process: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
    }

    for (i = 0; i < pno; i++) {
        int best_fit = -1;
        for (j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) {
                if (best_fit == -1 || bsize[j] < bsize[best_fit]) {
                    best_fit = j;
                }
            }
        }
        if (best_fit != -1) {
            allocation[i] = best_fit;
            bsize[best_fit] -= psize[i];
        } else {
            allocation[i] = -1; // Process not allocated
        }
    }

    printf("\nProcess No\tProcess Size\tBlock no\n");
    for (i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}
