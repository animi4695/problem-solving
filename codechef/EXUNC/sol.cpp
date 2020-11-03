#include <iostream>
#include <set>

using namespace std;

set<int> subarrays;

int findans(int x)
{ // The second type of query
    // For any element k, the first element in the subarray of element k is -
    // the largest element j in subarray such that j<=k

    // Find the first element j in such that j > k
    // j-- (The previous element)

    auto it = subarrays.upper_bound(x); // strictly greater than( > )
    it--;

    return *it;
}

void remove(int x)
{
    subarrays.erase(x);
}
int main()
{

    // N - size of the array = N - 1e6
    // A[N] - positive integers
    // We are dividing the entire array into subarrays
    // If i and i+1 are in the same subarray then A[i+1]%A[i] == 0
    // S(i) is the index of the subarray in which the ith element lies
    // Q queries Q = 2e5
    // 1 i A = Changing A[i] to X
    // 2 i = We have to output the first element in the same subarray as i

    // Required Complexity is either O(Q) or O(QlogN)

    // In this problem. we have to form continuous sub arrays
    // For any index i, if A[i+1]%A[i] == 0, then we should place i+1 and i in the same subarray

    // How do we store the partitions of the subarrays?
    // Since the subarrays are all contiguous, we only need to store the first element of each subarray
    // {2, 6, 5, 10, 20, 3} - Array
    // Subarrays -> {2 , 6}, { 5, 10, 20} , {3}
    // We will be storing only the first index of these subarrays = {1,3,6}

    // For the second type of query, we need to output the first element of the subarray of index k
    // For any element k, the first element in the subarray of element k is -
    // the largest element j in subarray such that j<=k

    // We need a data structure that can - (SET)
    // Store the elements in sorted order
    // Erase elements in O1) or O(logN)
    // find the largest element j in subarray such that j<=k in O(1) or O(logN)

    int n, q;
    cin >> n >> q;
    int A[n];

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    // We need to create the subarrays
    subarrays.insert(1); // 1 will always be the start of the subarray
    for (int i = 2; i <=n; i++)
    {
        // For any index i, if A[i+1]%A[i] == 0, then we should place i+1 and i in the same subarray

        if (A[i] % A[i - 1] == 0)
            continue;
        // We skip because we have already stored the start of the subarray

        subarrays.insert(i);
    } // Created the basic partitions before any queries takes place

    for(auto i : subarrays){
        cout<<i<<endl;
    }

    while (q--)
    {
        int type, i;
        cin >> type >> i;
        if (type == 1)
        {
            cin >> A[i]; // Update the A(i)
            // There are 4 things that can happen
            //   A[i] and A[i-1] can now be in the same subarray or not
            //   A[i] and A[i+1] can now be in the same subarray or not

            if (i > 1)
            {
                if ((findans(i) == i && ((A[i] % A[i - 1]) == 0)))
                {
                    // A[i] and A[i-1] are in subarray. so remove A[i]
                    remove(i);
                }
                else if ((findans(i) < i && ((A[i] % A[i - 1]) != 0)))
                {
                    // Earlier they were in the subarray, We need to insert the new element to separate i
                    subarrays.insert(i);
                }
            }

            if (i < n)
            {
                // checking for may not be in the same sub array
                if((findans(i + 1) > i && ((A[i + 1] % A[i]) == 0)))
                {
                    remove(i + 1);
                }
                else if ((findans(i + 1) <= i) && ((A[i + 1] % A[i]) != 0))
                {
                    subarrays.insert(i + 1);
                }
            }
        }
        else
        {
            cout << findans(i) << endl;
        }
    }

    return 0;
}