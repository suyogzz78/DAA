#include <stdio.h>
#include <time.h>

int gcdExtended(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcdExtended(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) {
        return -1;
    } else {
        return (x % m + m) % m;
    }
}

int chineseRemainderTheorem(int *a, int *m, int k) {
    int M = 1;
    for (int i = 0; i < k; i++) {
        M *= m[i];
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        int Mi = M / m[i];
        int inv = modInverse(Mi, m[i]);
        if (inv == -1) {
            return -1;
        }
        result += a[i] * Mi * inv;
    }

    return result % M;
}

int main() {
    int k;
    clock_t start, end;
    printf("Enter the number of equations: ");
    scanf("%d", &k);

    int a[k], m[k];

    printf("Enter the remainders (a_i values): ");
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the moduli (m_i values): ");
    for (int i = 0; i < k; i++) {
        scanf("%d", &m[i]);
    }

 
    start = clock();

    int result = chineseRemainderTheorem(a, m, k);

    if (result == -1) {
        printf("No solution exists.\n");
    } else {
        printf("The solution is: x = %d\n", result);
    }

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
