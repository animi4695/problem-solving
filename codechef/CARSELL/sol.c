#include <stdio.h>
#define modulo 1000000007
int GetMax(int arr[], int size);

int GetMaxIndex(int arr[], int size){
    int i;
    int max = arr[0];
    int max_index = 0;
    for(i = 0; i< size; i++){
        if(arr[i] > max){
            max = arr[i];
            max_index = i;
        }
    }

    return max_index;
}

int main()
{

    int t;
    long long int sum = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        int arr_size = sizeof(arr) / sizeof(arr[0]);

        // Get Max ele
        for (int j = 0; j < arr_size; j++)
        {
            if (arr[GetMaxIndex(arr, arr_size)] - j > 0)
            {
                sum = sum + arr[GetMaxIndex(arr, arr_size)] - j;
                arr[GetMaxIndex(arr, arr_size)] = 0;
            }
        }

        printf("%lld\n", sum % modulo);
    }
    return 0;
}