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

int solveModularEquation(int a, int b, int m) {
    int g, x, y;
    g = gcdExtended(a, m, &x, &y);
    if (b % g != 0) {
        return -1;
    }

    a /= g;
    b /= g;
    m /= g;

    int inv = modInverse(a, m);
    if (inv == -1) {
        return -1;
    }

    return (inv * b) % m;
}

int main() {
    int a, b, m;
    clock_t start, end;
    printf("Enter the values of a, b, and m (a * x ≡ b (mod m)): ");
    scanf("%d %d %d", &a, &b, &m);

 
    start = clock();

    int solution = solveModularEquation(a, b, m);

    if (solution == -1) {
        printf("No solution exists\n");
    } else {
        printf("The solution is: x = %d\n", solution);
    }

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
