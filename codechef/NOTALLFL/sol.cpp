#include <iostream>

// PARITIAL SOLUTION - NAIVE Approach
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        int cakes[6];
        for (int i = 0; i < n; i++)
        {
            std::cin >> cakes[i];
        }

        int maxLen = 0;
        int tempLen = 0;
        int prev = cakes[0];
        for (int i = 0; i < n; i++)
        {
            if(cakes[i] != prev){
                if(tempLen > maxLen)
                    maxLen = tempLen;
                tempLen = 0;
            }
            prev = cakes[i];
            tempLen += 1;
        }
        if(maxLen < tempLen){
            maxLen = tempLen;
        }
        std::cout << maxLen << std::endl;
    }
    return 0;
}