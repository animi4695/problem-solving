#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Subtask - 1
int main()
{
    long long int n;
    cin >> n;
    long long int cust[n];

    for (long long int i = 0; i < n; i++)
    {
        cin >> cust[i];
    }
    int cust_size = sizeof(cust) / sizeof(cust[0]);
    sort(cust, cust + cust_size);
    long long int Max = -1;

    for (long long int i = 0; i < n; i++)
    {
        if (((n - i) * cust[i]) > Max)
        {
            Max = ((n - i) * cust[i]);
        }
    }
    cout << Max << endl;

    return 0;
}