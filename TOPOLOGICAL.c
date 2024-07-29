#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100 // Maximum number of vertices in the graph

typedef struct Graph {
    int numVertices;
    int** adjMatrix;
    int* indegree;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjMatrix = malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = calloc(vertices, sizeof(int));
    }

    graph->indegree = calloc(vertices, sizeof(int));

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->indegree[dest]++;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("\n Vertex %d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d -> ", j);
            }
        }
        printf("NULL\n");
    }
}

void topologicalSort(Graph* graph) {
    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue vertices with no incoming edges
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int* topOrder = malloc(graph->numVertices * sizeof(int));

    while (front != rear) {
        int current = queue[front++];

        topOrder[count++] = current;

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[current][i] == 1) {
                if (--graph->indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (count != graph->numVertices) {
        printf("There exists a cycle in the graph\n");
        return;
    }

    printf("Topological Sort: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topOrder[i]);
    }
    printf("\n");

    free(queue);
    free(topOrder);
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Graph adjacency list representation:\n");
    printGraph(graph);

    // Time complexity calculation with delay
    clock_t start, end;
    double cpu_time_used;
    double delay_time = 0.001; // Delay time in seconds

    start = clock();
    topologicalSort(graph);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to perform topological sort: %f seconds\n", cpu_time_used);
    printf("Time complexity: O(V + E)\n");

    // Adding delay to factor in delay time
    double total_time_with_delay = cpu_time_used + (vertices * vertices * delay_time);
    printf("Total time with delay factored in: %f seconds\n\n", total_time_with_delay);

    // Free graph memory
    for (int i = 0; i < vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph->indegree);
    free(graph);

    return 0;
}
