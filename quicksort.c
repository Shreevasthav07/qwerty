#include<stdio.h>

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int low, int high){
    int pivot = a[high];
    int i = low -1;
    for(int j=low;j<high;j++){
        if(a[j]>= pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;

}

void quicksort(int a[],int low, int high){
    if(low<=high){
        int p = partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

int main(){
  int a[]={2,6,3,7,9,11,13,14,17,15};
  int n=10;
  quicksort(a,0,n-1);
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}
