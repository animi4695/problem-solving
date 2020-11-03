#include <stdio.h>
#define MAX 101
int main()
{

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n = 0;
        scanf("%d", &n);
        int seq[n];
        int count = 0;
        int isSocial = 1;
        int isStart =0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &seq[j]);
            // printf("%d - %d\n", j,count);
            

            if(seq[j] == 0 && isStart > 0){
                count ++;
            }

            if(seq[j] == 1 && count == 0){
                isStart = 1;
                count++;
            }
            else if (seq[j] == 1 && count != 0  && count < 6)
            {
                isSocial = 0;
                count = 0;
                isStart = 0;
            }
            if(seq[j] == 1 && count >=6){
                count = 1;
            }
        }

        if (isSocial > 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}