#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    
    for (int L = 2; L < n; L++) {
        for (int i = 1, j = i + L - 1; j < n; i++, j++) {
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int *p = malloc((n + 1) * sizeof(int));
    if (!p) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the dimensions array: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    
    clock_t start = clock();
    int minCost = matrixChainOrder(p, n + 1);

    
    printf("Minimum multiplications: %d\n", minCost);
    clock_t end = clock();
    printf("Execution time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    free(p);
    return 0;
}
