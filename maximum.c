#include <stdio.h>

// Function to find the highest value in an array
int findMax(int arr[], int n) {
    // Initialize max with the first element of the array
    int max = arr[0];

    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if the current element is greater
        }
    }

    return max; // Return the maximum value found
}

int main() {
    int arr[] = {1, 3, 7, 0, 5, 9, 2}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    int max = findMax(arr, n); // Find the maximum value in the array

    printf("The highest value in the array is: %d\n", max); // Print the maximum value

    return 0;
}
