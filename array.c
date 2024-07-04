#include <stdio.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to check if all elements in the array are distinct
bool areDistinct(int arr[], int n) {
    // Initialize an empty hash set
    bool hashSet[MAX_SIZE] = {false};

    for (int i = 0; i < n; i++) {
        // Check if the element is already in the hash set
        if (hashSet[arr[i]]) {
            return false; // Not all elements are distinct
        }
        // Add the element to the hash set
        hashSet[arr[i]] = true;
    }

    return true; // All elements are distinct
}

int main() {
    int arr[] = {1, 3, 2, 4}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    if (areDistinct(arr, n)) {
        printf("All elements are distinct.\n");
    } else {
        printf("Not all elements are distinct.\n");
    }

    return 0;
}
