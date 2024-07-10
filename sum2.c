//SumOFNos(Divide&Conquer)
#include <stdio.h>

// Function to calculate the sum of elements in an array using divide and conquer
int arraySumDC(int arr[], int l, int r) {
    if (l == r) {
        return arr[l]; // Base case: when l and r point to the same element
    } else {
        int m = (l + r) / 2; // Find the middle index

        // Recursively calculate sum of left and right halves
        int leftSum = arraySumDC(arr, l, m);
        int rightSum = arraySumDC(arr, m + 1, r);

        // Return the sum of left and right halves
        return leftSum + rightSum;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Calculate the sum of elements in the array using divide and conquer
    int sum = arraySumDC(arr, 0, size - 1);

    // Print the sum
    printf("Sum of elements in the array: %d\n", sum);

    return 0;
}
