#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

bool fun(int a, int b)
{
    return a > b;
}
int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        int n, z;
        cin >> n >> z;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            pq.push(a);
        }

        int res = 0;
        while (!pq.empty() && z > 0)
        {
            int ele = pq.top();
            // cout<<ele<<"-";
            pq.pop();
            res++;
            z = z - ele;
            ele = ele / 2;
            if (ele > 0)
            {
                pq.push(ele);
            }
        }

        if (z <= 0)
        {
            cout << res << endl;
        }
        else
        {
            cout << "Evacuate" << endl;
        }
    }
    return 0;
}