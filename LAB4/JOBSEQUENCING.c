#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void printJobSequence(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);
    int result[n], slot[n];
    for (int i = 0; i < n; i++) slot[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (j < n && slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    printf("Job sequence:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i])
            printf("Job %d (Profit: %d)\n", jobs[result[i]].id, jobs[result[i]].profit);
    }
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    printf("Enter job details (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    start = clock();
    printJobSequence(jobs, n);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime executed: %f seconds\n", cpu_time_used);

    return 0;
}