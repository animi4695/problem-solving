#include <iostream>
#include<map>
#include<algorithm>

// Complete solution for subtest -2

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        long long cakes[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> cakes[i];
        }
        long long i = 0;
        long long j = 0;
        long long ans = 0;
        std::map<long long, long long> mp;
        while(i<n){
            if(mp.size() < k){
                mp[cakes[i]]++;
                if((long long)mp.size() < k)
                    ans = std::max(ans, i-j+1);
                i++;
            }
            else{
                mp[cakes[j]]--;
                if(mp[cakes[j]] == 0)
                    mp.erase(cakes[j]);
                j++;
            }
        }
        std::cout<<ans<<std::endl;        
    }
    return 0;
}