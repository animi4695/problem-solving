#include <iostream>
#include <vector>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int S[n];

        for (int i = 0; i < n; i++)
        {
            std::cin >> S[i];
        }

        int min = S[0];
        long long int ans = 0;
        for(int i = 0; i< n;i++){
            if(S[i]<min){
                min = S[i];
                ans = ans + S[i];
            }
            else{
                ans = ans + min;
            }
        }
        std::cout<<ans<<std::endl;

        // ---------- NAIVE SOLUTION --------------
        // int maxCapacity[n];
        // for (int i = 0; i < n; i++)
        // {
        //     int min = S[0];
        //     for (int j = 0; j <= i; j++)
        //     {
        //         if (S[j] <= min)
        //         {
        //             min = S[j];
        //         }
        //     }
        //     maxCapacity[i] = min;
        // }

        // long long int sum = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     sum = sum + maxCapacity[i];
        // }

        // std::cout << sum << std::endl;

        // -------------------------------------------
    }
    return 0;
}