#include <stdio.h>
#include <limits.h>
#define V 5  // number of vertices
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int parent[V];   // to store MST
    int key[V];      // minimum edge weight
    int visited[V];  // 1 if vertex is already in MST

    // initialize
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;      // start from vertex 0
    parent[0] = -1;  // root has no parent

    // build MST
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;

        // find vertex with minimum key value not yet visited
        for (int v = 0; v < V; v++)
            if (!visited[v] && key[v] < min)
                min = key[v], u = v;

        visited[u] = 1;  // include u in MST

        // update key and parent of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // print the MST
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);

    return 0;
}
