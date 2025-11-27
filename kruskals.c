#include <stdio.h>

struct Edge {
    int u, v, w;   // source, destination, weight
};

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[], int a, int b) {
    int x = find(parent, a);
    int y = find(parent, b);
    parent[x] = y;
}

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edges[50];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Sort edges by weight (ascending)
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[50];
    for (int i = 0; i < n; i++)
        parent[i] = i;   // initialize disjoint sets

    struct Edge mst[50];
    int mstIndex = 0, totalCost = 0;

    // Kruskal's algorithm
    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(parent, u) != find(parent, v)) {
            mst[mstIndex++] = edges[i];
            totalCost += w;
            unionSet(parent, u, v);
        }
    }

    // Print MST
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (int i = 0; i < mstIndex; i++) {
        printf("%d - %d : %d\n", mst[i].u, mst[i].v, mst[i].w);
    }

    printf("\nTotal Minimum Cost = %d\n", totalCost);

    return 0;
}
