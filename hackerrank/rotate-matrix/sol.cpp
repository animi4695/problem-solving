#include <iostream>
#include <limits>

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

        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                cin>>arr[i][j];
            }
        }

        // Transpose of Matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            int j = 0;
            int k = n-1;

            while(j < k) {
                swap(arr[i][j], arr[i][k]);
                j++;
                k--;
            }
        }


        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}