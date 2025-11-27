#include<stdio.h>
#define INF 9999
#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int path[MAX]; //stores current path
int best_path[MAX]; // stores minimum cost route
int min_cost = INF;

void TSP(int level,int current_cost){
    if (level==n){
        int total_cost = current_cost+cost[path[level-1]][path[0]];
        if (total_cost<min_cost){
            min_cost = total_cost;
            for(int i=0;i<n;i++){
                best_path[i] = path[i];
            }   
        }
        return;
    }
    for(int city =1;city<n;city++){
        if(!visited[city]){
            visited[city]=1;
            path[level] = city;

            int new_cost = current_cost+cost[path[level-1]][city];
            if (new_cost < min_cost){
                TSP(level+1,new_cost);
            }
            visited[city]=0;
        }
    }

}

int main(){
    
    printf("Enter number of Cities: ");
    scanf("%d",&n);
    
    printf("Enter Cost Matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);

        }
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    path[0]=0;
    visited[0]=1;
    min_cost = INF;

    TSP(1,0);
    printf("\nOptimal Tour:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> ", best_path[i]);
    printf("0\n");

    printf("\nMinimum Cost = %d\n", min_cost);

    return 0;
}
