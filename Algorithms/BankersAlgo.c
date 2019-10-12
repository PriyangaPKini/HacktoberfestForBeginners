#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void main() {
    int i, j, m, n, count=0, exec;
    bool safe = false;

    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    printf("Enter the no. of resource types: ");
    scanf("%d", &m);

    int avlbl[m], max[n][m], alloc[n][m], need[n][m], work[m], finish[n];

    for (i=0; i<n; i++)
        finish[i] = 0;

    printf("Enter Available Resources: \n");
    for (i=0; i<m; i++) {
        scanf("%d", &avlbl[i]);
        work[i] = avlbl[i];
    }

    printf("Enter Max. Resources: \n");
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf("%d\t ", &max[i][j]);

    printf("Enter Allocation: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while (count < n) {
        safe = false;
        for (i=0; i<n; i++) {
            if (!finish[i]) {
                exec = 1;
                for (j=0; j<m; j++) {
                    if (need[i][j] > work[j]) {
                        exec = 0;
                        break;
                    }
                }
                if (exec) {
                    printf("\nP%d is executing\n", i);
                    finish[i] = 1;
                    count++;
                    safe = true;
                    for (j=0; j<m; j++)
                        work[j] += alloc[i][j];
                    break;
                }
            }
        }

        if (!safe) {
            printf("The processes are in unsafe state.\n");
            exit(0);
        }

        printf("Work: \n");
        for (i = 0; i < m; i++)
            printf("%d ", work[i]);
        printf("\n");
    }

    printf("\nThe processes are in safe state. \n");
}