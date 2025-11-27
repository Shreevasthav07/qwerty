#include<stdio.h>
#define INF 9999

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter Cost Adjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Convert 0 (except diagonal) into INF
            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Floyd-Warshall Algorithm
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // Check if path i->k and k->j exist
                if(cost[i][k] != INF && cost[k][j] != INF) {
                    if(cost[i][j] > cost[i][k] + cost[k][j]) {
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cost[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}
