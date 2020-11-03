#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
int main()
{

    int n, m;
    cin >> n >> m;
    int A[n];
    int AlargestIndex = 0;
    int Alargest = 0;
    int B[m];
    int BsmallestIndex = 1e9 + 7;
    int Bsmallest = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] > Alargest)
        {
            Alargest = A[i];
            AlargestIndex = i;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        if (B[i] < Bsmallest)
        {
            Bsmallest = B[i];
            BsmallestIndex = i;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << AlargestIndex << " " << i << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == AlargestIndex)
        {
            continue;
        }
        cout << i << " " << BsmallestIndex << endl;
    }

    return 0;
}