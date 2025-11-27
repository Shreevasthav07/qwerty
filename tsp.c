#include <stdio.h>

#define INF 9999

int n;
int cost[10][10];
int visited[10];
int minCost = INF;

void tsp(int city, int count, int currentCost) {
    if (count == n) {
        if (cost[city][0] != INF) {
            int totalCost = currentCost + cost[city][0];
            if (totalCost < minCost)
                minCost = totalCost;
        }
        return;
    }

    for (int next = 0; next < n; next++) {
        if (!visited[next] && cost[city][next] != INF) {
            visited[next] = 1;
            tsp(next, count + 1, currentCost + cost[city][next]);
            visited[next] = 0; // backtrack
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 9999 for no path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;  // start from city 0
    tsp(0, 1, 0);

    printf("\nMinimum Cost of TSP Tour = %d\n", minCost);

    return 0;
}
