#include <stdio.h>
#include <time.h>

int extendedEuclidean(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);
    
    *x = y1;
    *y = x1 - (a / b) * y1;
    
    return gcd;
}

int main() {
    int a, b;
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    clock_t start, end;
    start = clock();

    int gcd = extendedEuclidean(a, b, &x, &y);
    printf("The GCD of %d and %d is %d\n", a, b, gcd);
    printf("The coefficients are: x = %d, y = %d\n", x, y);

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
