#include <iostream>
#include <limits>
#include<cmath>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n&1) n++;
        int mid = n>>1;
        for (int i = 1; i <= mid; i++)
        {
            // print the spaces.. before the STAR
            for (int j = 1; j <= (mid - i); j++)
            {
                cout << " ";
            }

            if (i == 1)
            {
                cout << "*";
            }
            else
            {
                cout << "*";
                // print hollow spaces
                for (int j = 1; j <= (2*i-3); j++)
                {
                    cout << " ";
                }
                cout << "*";
            }
            cout<<"\n";
        }

        for (int i = mid+1; i < n; i++)
        {
            // print spaces
            for (int j = 1; j <= i-mid; j++)    cout<<" ";

            if(i == n-1) cout<<"*";
            else{
                cout<<"*";
                for (int j = 1; j <= 2*(n-i) - 3; j++)   cout<<" ";
                cout<<"*";
            }
            cout<<"\n";
        }
        
    }

    return 0;
}