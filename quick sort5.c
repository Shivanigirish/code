#include <stdio.h>
#include <string.h>
#include<time.h>

// Function declarations
void quickSort(char arr[], int low, int high);
int partition(char arr[], int low, int high);
void swap(char* a, char* b);
void printArray(char arr[], int size);

int main() {
    char str[100];
    clock_t start,end;
    printf("*********************************QUICK SORT***********************************\n");
    printf("AUTHOR: SHIVANI GIRISH\n");
    printf("DATE:17/07/24\n");
    printf("******************************************************************************\n");

    // Input the string
    printf("PLEASE ENTER VALUES TO SORT ");
    scanf("%s", str);

    int n = strlen(str);
    start=clock();


    // Display original string
    printf("Original string: %s\n", str);

    // Perform Quick Sort on the string
    quickSort(str, 0, n - 1);
    end = clock();

    // Display sorted string
    printf("Sorted string: %s\n", str);
    double total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("THE TIME TAKEN TO SORT THIS ARRAY IS: %f seconds\n", total_time);

    return 0;
}

// Function to perform Quick Sort
void quickSort(char arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array
int partition(char arr[], int low, int high) {
    // Pivot (Element to be placed at right position)
    char pivot = arr[high];
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to swap two elements
void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

// Function to print an array (string)
void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%c", arr[i]);
    printf("\n");
}

