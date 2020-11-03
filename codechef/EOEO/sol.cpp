#include <iostream>

using namespace std;
int doCalc(int ts);


int doCalc(int ts)
{
    int ans = 0;
    for (int i = ts; i > 1; i = i - 2)
    {
        // cout<<i<<"-";
        if ((((i / 2) % 2) == 0) && (((ts / 2) % 2) != 0) && ((i / 2) > 0) && ((ts / 2) > 0))
        {
            // cout<<i<<"-";
            ans++;
        }
        else if((((i / 2) % 2) == 0) && (((ts / 2) % 2) == 0) && ((i / 2) > 0) && ((ts / 2) > 0)){
            doCalc(ts/2);
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ts;
        cin >> ts;
        int ans = 0;
        if (ts % 2 == 0)
        {
            // TS Even
            // for (int i = ts; i > 1; i = i - 2)
            // {
            //     // cout<<i<<"-";
            //     if ((((i / 2) % 2) == 0) && (((ts / 2) % 2) != 0) && ((i / 2) > 0) && ((ts / 2) > 0))
            //     {
            //         // cout<<i<<"-";
            //         ans++;
            //     }
            // }       
            ans = doCalc(ts);
        }
        else
        {
            // TS Odd
            ans = ts / 2;
        }

        cout << ans << endl;
    }

    return 0;
}
