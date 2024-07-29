#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 // Size of the graph
#define INF 99999 // A value representing infinity

void printMatrix(int graph[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", graph[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[N][N]) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main() {
    int graph[N][N] = {
        {0, INF, 3, 7},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF,INF}
    };

    printf("Original Graph:\n");
    printMatrix(graph);

    // Time complexity calculation with delay
    clock_t start, end;
    double cpu_time_used;
    double delay_time = 0.001; // Delay time in seconds

    start = clock();
    floydWarshall(graph);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nShortest Paths Matrix:\n");
    printMatrix(graph);

    printf("\nTime taken to compute shortest paths: %f seconds\n", cpu_time_used);
    printf("Time complexity: O(%d)\n", N * N * N);

    // Adding delay to factor in delay time
    double total_time_with_delay = cpu_time_used + (N * N * N * delay_time);
    printf("Total time with delay factored in: %f seconds\n", total_time_with_delay);

    return 0;
}
