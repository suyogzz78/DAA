#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int millerRabinTest(long long n, int k) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x = modExp(a, d, n);

        if (x == 1 || x == n - 1) {
            continue;
        }

        int isComposite = 1;
        for (int j = 0; j < r - 1; j++) {
            x = modExp(x, 2, n);
            if (x == n - 1) {
                isComposite = 0;
                break;
            }
        }

        if (isComposite) {
            return 0;
        }
    }

    return 1;
}

int main() {
    long long n;
    int k;
    clock_t start, end;
    printf("Enter a number to test for primality: ");
    scanf("%lld", &n);

    printf("Enter the number of iterations for Miller-Rabin Test (recommended k >= 5): ");
    scanf("%d", &k);

  
    start = clock();

    if (millerRabinTest(n, k)) {
        printf("%lld is likely prime.\n", n);
    } else {
        printf("%lld is composite.\n", n);
    }

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
