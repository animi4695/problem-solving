#include<stdio.h>
#include<stdlib.h>

int smallestsum(int *a, int n){
    int min=a[0];
    for(int i=0;i<n; i++){
       if(a[i]<min){
            min = a[i];
       }
    }
    int temp=a[0];
    for(int i=0;i<n-1;i++){
        if(a[i]<temp && a[i]<min){
            temp=a[i];
        }
    }
    return min+temp;
}

int main(){
    int T,N,res;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int *arr;
        scanf("%d",&N);
        arr = (int*)malloc(sizeof(int) * N);
        for(int j=0;j<N;j++){
            scanf("%d",&arr[j]);
        }
        res = smallestsum(arr,N);
        printf("%d",res);
    }
}

