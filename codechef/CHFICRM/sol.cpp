#include <iostream>
#include <map>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int res = 0;
        map<int, int> money;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 5)
            {
                money[5]++;
            }
            else if (arr[i] == 10)
            {
                if (money[5] > 0)
                {
                    money[5]--;
                    money[10]++;
                }
                else
                {
                    res = 1;
                    break;
                }
            }
            else if (arr[i] == 15)
            {
                if (money[10] > 0)
                {
                    money[10]--;
                    money[15]++;
                }
                else if(money[5] >= 2){
                    money[5]--;
                    money[5]--;
                    money[15]++;
                }
                else
                {
                    res = 1;
                    break;
                }
            }
        }
        if (res == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}