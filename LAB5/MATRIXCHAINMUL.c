#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int matrixChainOrder(int p[], int n) {
int m[n][n];
for (int i = 1; i < n; i++)
m[i][i] = 0;
for (int L = 2; L < n; L++) { // L is chain length
for (int i = 1; i < n - L + 1; i++) {
int j = i + L - 1;
m[i][j] = INT_MAX;
for (int k = i; k <= j - 1; k++) {
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
int* p = (int*)malloc((n + 1) * sizeof(int));
if (p == NULL) {
printf("Memory allocation failed\n");
return 1;
}
printf("Enter the dimensions array (of size %d):\n", n + 1);
for (int i = 0; i < n + 1; i++) {
scanf("%d", &p[i]);
}
clock_t start, end;
double cpu_time_used;
start = clock();
int minCost = matrixChainOrder(p, n + 1);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Minimum number of multiplications is %d\n", minCost);
printf("\nTime executed: %f seconds\n", cpu_time_used);
free(p);
return 0;
}