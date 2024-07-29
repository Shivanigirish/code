#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 // Size of the graph

void printMatrix(int graph[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void warshall(int graph[N][N]) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main() {
    int graph[N][N] = {
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 1}
    };

    printf("Original Graph:\n");
    printMatrix(graph);

    // Time complexity calculation with delay
    clock_t start, end;
    double cpu_time_used;
    double delay_time = 0.001; // Delay time in seconds

    start = clock();
    warshall(graph);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTransitive Closure:\n");
    printMatrix(graph);

    printf("\nTime taken to compute transitive closure: %f seconds\n", cpu_time_used);
    printf("Time complexity: O(%d)\n", N * N * N);

    // Adding delay to factor in delay time
    double total_time_with_delay = cpu_time_used + (N * N * N * delay_time);
    printf("Total time with delay factored in: %f seconds\n", total_time_with_delay);

    return 0;
}
