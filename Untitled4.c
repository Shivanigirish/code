//Author: shivani
//Date: 4.7.24
//Time: 11:25AM
//Modified date:
#include <stdio.h>

int factorial(int n);

int main() {
    short int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        time_t start, end;
        start = time(NULL);
        int result = factorial(num);
        end = time(NULL);

        printf("Factorial of %d is %d\n", num, result);

        double elapsed_time = difftime(end, start);
        printf("Start time of factorial function: %s", ctime(&start));
        printf("End time of factorial function: %s", ctime(&end));
        printf("Elapsed time for factorial function: %.2f seconds\n", elapsed_time);

    }

    return 0;
}

int factorial(int n) {
    if (n == 0 || n==1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
