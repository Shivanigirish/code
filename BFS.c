#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Maximum number of vertices in the graph

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void topologicalSortUtil(int v, int visited[], int* stack, int* stackIndex, Graph* graph) {
    visited[v] = 1;
    Node* temp = graph->adjLists[v];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            topologicalSortUtil(adjVertex, visited, stack, stackIndex, graph);
        }
        temp = temp->next;
    }
    stack[(*stackIndex)++] = v;
}

void topologicalSort(Graph* graph) {
    int* stack = malloc(graph->numVertices * sizeof(int));
    int stackIndex = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            topologicalSortUtil(i, graph->visited, stack, &stackIndex, graph);
        }
    }

    printf("Topological Sort: ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(stack);
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

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to perform topological sort: %f seconds\n", cpu_time_used);
    printf("Time complexity: O(V + E)\n");

    // Adding delay to factor in delay time
    double total_time_with_delay = cpu_time_used + (vertices * vertices * delay_time);
    printf("Total time with delay factored in: %f seconds\n\n", total_time_with_delay);

    // Free graph memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}
