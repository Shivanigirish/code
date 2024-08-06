#include <stdio.h>
#include <stdlib.h>
int comparator(const void* a, const void* b)
{
 const int (*x)[3] = a;
 const int (*y)[3] = b;
 return (*x)[2] - (*y)[2];
}
void initialize(int parent[], int rank[], int n)
{
 for (int i = 0; i < n; i++) {
 parent[i] = i;
 rank[i] = 0;
 }
}
int findParent(int parent[], int i)
{
 if (parent[i] != i)
 parent[i] = findParent(parent, parent[i]);
 return parent[i];
}
void unionSets(int parent[], int rank[], int u, int v)
{
 u = findParent(parent, u);
 v = findParent(parent, v);
 if (rank[u] < rank[v])
 parent[u] = v;
 else if (rank[u] > rank[v])
 parent[v] = u;

else {
 parent[v] = u;
 rank[u]++;
 }
}
void kruskalMST(int edges[][3], int n, int numEdges)
{
 qsort(edges, numEdges, sizeof(edges[0]), comparator);
int parent[n], rank[n];
 initialize(parent, rank, n);
 printf("Edges in the constructed MST:\n");
 int minCost = 0;
for (int i = 0; i < numEdges; i++) {
 int u = findParent(parent, edges[i][0]);
 int v = findParent(parent, edges[i][1]);
 if (u != v) {
 printf("%d -- %d == %d\n", edges[i][0], edges[i][1], edges[i][2]);
 minCost += edges[i][2];
 unionSets(parent, rank, u, v);
 }
 }
 printf("Minimum Cost Spanning Tree: %d\n", minCost);
}
int main()
{
 int edges[][3] = {{0, 1, 10},
 {0, 2, 6},
 {0, 3, 5},
 {1, 3, 15},
 {2, 3, 4} };

int numEdges = sizeof(edges) / sizeof(edges[0]);
 kruskalMST(edges, 4, numEdges);
return 0;
}
