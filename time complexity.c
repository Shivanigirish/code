#include <stdio.h>

// Function to compute power using decrease by constant (exponentiation by squaring)
long long power(int x, int n) {

    long long result = 1;
    long long base = x;

    while (n > 0) {
        if (n % 2 == 1) { // If n is odd
            result *= base;
        }
        base *= base; // Square the base
        n /= 2; // Divide n by 2
    }

    return result;
}

int main() {
    int x, n;
    printf("**********COMPUTE a^n USING DECREASE BY CONSTANT************\n");
    printf("AUTHOR: SHIVANI GIRISH\n");
    printf("DATE: 17.7.24\n");
    printf("**************************\n");

    // Input base (x) and exponent (n)
    printf("PLEASE ENTER BASE (a): ");
    scanf("%d", &x);
    printf("PLEASE ENTER EXPONENT (n): ");
    scanf("%d", &n);

    // Compute power x^n using the function
    long long result = power(x, n);

    // Output the result
    printf("%d raised to the power %d is: %lld\n", x, n, result);

    return 0;
}
