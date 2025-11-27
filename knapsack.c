#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n, W;
    printf("Enter number of items: ");
    scanf("%d",&n);
    int profit[n],weight[n];
    float ratio[n];

    printf("Enter Profits:\n");
    for(int i = 0;i<n;i++) scanf("%d",&profit[i]);
    printf("Enter Weights:\n");
    for(int i = 0;i<n;i++) scanf("%d",&weight[i]);
    printf("Enter capacity of Knapsack: ");
    scanf("%d",&W);

    for(int i=0;i<n;i++)
        ratio[i] = (float)profit[i]/weight[i];
    
    for(int i = 0; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                swap(&profit[j],&profit[j+1]);
                swap(&weight[j],&weight[j+1]);

                float t = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = t;
            }
        }
    }

    float totalProfit = 0;
    int capacity = W;
    for (int i = 0; i<n;i++){
        if(weight[i]<= capacity){
            totalProfit+=profit[i];
            capacity -=weight[i];
        }
        else{
            totalProfit += (float)capacity*ratio[i];
            break;
        }
    }
    printf("Maximum Profit = %.2f\n",totalProfit);
    return 0;
}
