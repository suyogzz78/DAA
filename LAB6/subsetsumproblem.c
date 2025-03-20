#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool subsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    clock_t start, end;
    start = clock();

    if (subsetSum(arr, n, sum)) {
        printf("There is a subset with the given sum %d.\n", sum);
    } else {
        printf("There is no subset with the given sum %d.\n", sum);
    }

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
