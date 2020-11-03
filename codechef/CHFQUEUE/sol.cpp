#include <iostream>
#include <stack>
#define lint long long

int main()
{
    lint n, k;
    std::cin >> n >> k;
    lint arr[n];
    for (lint i = 0; i < n; i++) std::cin >> arr[i];

    lint ans = 1;
    std::stack<std::pair<lint,lint>> st;
    for(lint i = 0;i<n; i++){
        while(!st.empty() && st.top().first > arr[i]){
            ans *= (i - st.top().second + 1);
            ans %= 1000000007;
            st.pop();
        }
        st.push(std::make_pair(arr[i], i));
    }
    std::cout<<ans<<std::endl;
    // fearfulness = i2-i1 +1
    // for each index i, find the j which is 1st junior to i
    // eg- 1 2 1 2
    //     - 1 - -
    // NAIVE SOLUTION - O(n^2)
    // int ans = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     int j = i;
    //     while (j < n)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             ans = ans * (j - i + 1);
    //             ans %= 1000000007;
    //             // std::cout<<"index i- " << i<<" index j - " << j <<"aaj -"<< j-i+1 <<" ans- "<<ans<< std::endl;
    //             break;
    //         }
    //         j++;
    //     }
    // }
    // std::cout << ans<< std::endl;
    return 0;
}