#include <stdio.h>
#include <time.h>

int knapsack(int weights[], int values[], int n, int capacity) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (weights[n - 1] > capacity) {
        return knapsack(weights, values, n - 1, capacity);
    } else {
        int include = values[n - 1] + knapsack(weights, values, n - 1, capacity - weights[n - 1]);
        int exclude = knapsack(weights, values, n - 1, capacity);
        return (include > exclude) ? include : exclude;
    }
}

int main() {
    int n, capacity;
    clock_t start, end;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);


    start = clock();

    int maxValue = knapsack(weights, values, n, capacity);
    printf("Maximum value that can be obtained: %d\n", maxValue);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
