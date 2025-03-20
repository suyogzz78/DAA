#include <stdio.h>
#include <time.h>

int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    clock_t start, end;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    start = clock();
    int gcd = euclideanGCD(a, b);
    printf("The GCD of %d and %d is %d\n", a, b, gcd);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
