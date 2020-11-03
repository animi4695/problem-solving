#include <iostream>

using namespace std;
// Subtask - 1
int main()
{
    int n;
    cin >> n;
    int cust[n];

    for (int i = 0; i < n; i++)
    {
        cin >> cust[i];
    }

    long long int Max = 0;
    long long int tempMax = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(cust[j] >=cust[i] ){
                Max = Max + cust[i];
            }
        }
        // cout<<"-" <<Max<<endl;
        if(tempMax < Max){
            tempMax = Max;
        }
        Max = 0;
    }

    cout <<tempMax;

    return 0;
}