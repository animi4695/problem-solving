#include <iostream>
#include <limits>
#include<vector>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n][n];
        // Read Input matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        int i = 0;
        int j = n - 1;
        int k = 0, l = 0 , sum = 0;
        vector<int> result;
        while (i <= j)
        {
            k = i;
            l = j;
            sum = 0;
            while(k < n && l < n){
                sum += arr[k][l];
                k++;
                l++;
            }
            result.push_back(sum);
            j--;
            // cout<<sum;
        }

        i = 1;
        sum = 0;
        while(i<n) {
            k = i;
            l = 0;
            sum = 0;
            while(k< n && l < n){
                sum += arr[k][l];
                k++;
                l++;
            }
            result.push_back(sum);
            i++;
        }

        for(auto a: result){
            cout<<a<<" ";
        }
    }

    return 0;
}