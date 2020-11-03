#include <iostream>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        int maxProfit = 0;
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            int s, v, p;
            std::cin >> s >> p >> v;
            s++; // chef's store also added
            // std::cout << "PROFIT- " << ((p / s) * v)<<std::endl;
            if (maxProfit < ((p / s) * v))
            {
                maxProfit = (p / s) * v;
            }
        }
        std::cout << maxProfit << std::endl;
    }

    return 0;
}