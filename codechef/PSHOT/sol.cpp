#include <iostream>
#include <vector>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::string shots;
        std::cin>>shots;
        // std::cout<<shots;
        // for (int i = 0; i < 2 * n; i++)
        // {
        //     std::cin >> shots[i];
        // }
        int CA = 0, CB = 0, RA= n, RB = n;
        int ans = 2*n;
        for(int i=1;i<=shots.length(); i++)
        {
            if(shots[i-1] == '1' && (i%2 == 1)){
                CA++;
            }
            
            if(shots[i-1] == '1' && (i%2 == 0)){
                CB++;
            }

            if(i%2 == 0){
                RB--;
            }
            else{
                RA--;
            }

            if((CA-CB)>RB || (CB-CA)>RA){
                ans = i;
                break;
            }
        }
        std::cout<< ans << std::endl;
    }
    return 0;
}