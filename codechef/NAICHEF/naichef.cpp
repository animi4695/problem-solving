#include<stdio.h>
#include <stdlib.h>

void CountOccurrence(int *arr, int n, int a, int b, int *countA, int *countB)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == a)
        {
            (*countA) = (*countA) + 1;
        }
        if(arr[i] == b)
        {
            (*countB) = (*countB) + 1;
        }
    }
    //printf("%d %d\n", *countA, *countB);
    return;
}
int main()
{
    int T,N,A,B;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int *arr;
        int countA = 0, countB = 0;
        scanf("%d%d%d",&N,&A,&B);
        arr = (int*)malloc(sizeof(int) * N);
        for(int j=0;j<N;j++)
        {
            scanf("%d",&arr[j]);
        }
        CountOccurrence (arr, N, A, B, &countA, &countB);
        printf("%.10f\n", (float)(countA * countB)/(float)(N * N));
    }
    return 0;
}
