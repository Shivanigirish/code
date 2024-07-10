#include <stdio.h>

// Function to calculate the number of digits in binary representation
int countBinaryDigits(int decimalNumber) {
    int count = 0;
    // Handle the case where the number is 0 separately
    if (decimalNumber == 0) {
        return 1;  // 0 in binary representation has 1 digit
    }

    while (decimalNumber > 0) {
        decimalNumber /= 2;
        count++;
    }
    return count;
}

int main() {
    int decimalNumber;

    // Input the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Calculate and print the number of digits in its binary representation
    int numberOfDigits = countBinaryDigits(decimalNumber);
    printf("Number of digits in binary representation: %d\n", numberOfDigits);

    return 0;
}

