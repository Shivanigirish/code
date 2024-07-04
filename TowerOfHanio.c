#include <stdio.h>

// Function to move n disks from from_rod to to_rod using aux_rod
void towerOfHanoi(int n, char source, char destination, char temporary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, temporary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, temporary, destination, source);
}

int main() {
    int n; // Number of disks

    // Prompt the user for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods

    return 0;
}

