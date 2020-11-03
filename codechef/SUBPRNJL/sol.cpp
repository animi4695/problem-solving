#include<iostream>
#include<map>
#include<cmath>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define oset tree < pair<int, int> ,  null_type ,  less<pair<int, int>> ,  rb_tree_tag ,  tree_order_statistics_node_update >
using namespace std;
using namespace __gnu_pbds;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int ans = 0;
        int A[n];
        for(int i = 0 ;i <n;i++) cin>>A[i];

        // M * Length of subarray >= k
        // M = ceil(k/len of array)
        // X = kth smallest element of B
        // The kth smallest element of B would be ceil(k/m)th smallest element of S
        // F is the frequency of X in S(original subarray, before concatenation)
        // The subarray S is beautifull if F also occurs in S
        // We need to output the number of beautiful subarrays
        for (int  i = 0; i < n; i++)
        {
            int freq[2001];
            for(int i = 0 ; i< 2001; i++) freq[i] = 0;
            oset s;
            for (int j = i; j < n; j++)
            {
                int m = ceil(((double)k)/(j-i+1));
                int x = ceil(((double)k)/m);
                x--; // 0 based indexing
                // s is a pair because to support duplicates in a set, we add second one as frequency
                s.insert({A[j], freq[A[j]]++});
                // Find the the kth smallest number in Subarray in O(1) or O(logn)
                auto it = s.find_by_order(x);
                int element = (*it).first;
                int frequency = freq[element];
                if(freq[frequency] > 0) ans++;
            }
            
        }
        cout<<ans<<"\n";
        
    }
    
    return 0;
}