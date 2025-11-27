#include<stdio.h>

typedef struct Item{
    char name[10];
    float profit, weight, ratio;
}Item;

void swap(struct Item *a, struct Item *b){
    struct Item t = *a;
    *a =*b;
    *b = t;
}

int main(){
    int n; float capacity;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter Capacity of Knapsack");
    scanf("%f",&capacity);
    Item Items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter item %d name: ", i+1);
        scanf("%s", Items[i].name);

        printf("Enter profit: ");
        scanf("%f", &Items[i].profit);

        printf("Enter weight: ");
        scanf("%f", &Items[i].weight);

        Items[i].ratio = Items[i].profit / Items[i].weight;
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(Items[j].ratio<Items[j+1].ratio){
                swap(&Items[j],&Items[j+1]);
            }
        }
    }
    printf("\nItem  Profit  Weight  Ratio\n");
    for(int i=0;i<n;i++){
        printf("%s    %.2f     %.2f     %.2f\n",Items[i].name, Items[i].profit, Items[i].weight, Items[i].ratio);
    }
    float total = 0;
    for(int i=0;i<n;i++){
        if (capacity ==0){
            break;
        }
        if(Items[i].weight<=capacity){
            printf("%s -> Full\n", Items[i].name);
            total+=Items[i].profit;
            capacity-=Items[i].weight;
        }
        else{
            float frac = capacity/Items[i].weight;
            printf("%s -> Partial (%.2f/%.2f)\n",Items[i].name,capacity,Items[i].weight);
            total+=frac*Items[i].profit;
            capacity = 0;
        }
    }
    printf("\nMaximum Profit = %.2f\n", total);
    return 0;
}
