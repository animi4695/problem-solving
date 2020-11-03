#include <iostream>
#include <set>

using namespace std;

set<int> subarrays;

int findAns(int x){
    auto itr = subarrays.upper_bound(x);
    itr--;
    return *itr;
}

void remove(int x){
    subarrays.erase(x);
}
int main()
{
    int n, q;
    cin >> n >> q;
    int A[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    // Pre query Code
    // 1st is included by default
    subarrays.insert(1);

    for (int i = 2; i <= n; i++)
    {
        // We always insert the first index of the subarry only
        if (A[i] % A[i - 1] == 0)
            continue;
        subarrays.insert(i);
    } // Created the sub-array as per the valid paritions

    while (q--)
    {
        int type, i;
        cin >> type >> i;
        if (type == 1)
        {
            // 1st Query
            cin >> A[i];
            // Valid partition order is disturbed, so lets re-construct it

            // A[i], A[i+1] may be in same subarray
            // A[i], A[i+1] maynot be in same subarray
            // A[i], A[i-1] may be in same subarray
            // A[i], A[i-1] maynot be in same subarray
            if (i > 1)
            {
                if(findAns(i) == i && A[i]%A[i-1] == 0){
                    remove(i);
                }
                else if(findAns(i) < i && A[i]%A[i-1] != 0){
                    subarrays.insert(i);
                }
            }

            if(i<n){
                if(findAns(i+1) > i && A[i+1]%A[i] == 0){
                    remove(i+1);
                }
                else if(findAns(i+1) <=i && A[i+1]%A[i] != 0 ){
                    subarrays.insert(i+1);
                }
            }
        }
        else
        {
            // 2nd Query
            cout<<findAns(i)<<endl;
        }
    }

    return 0;
}