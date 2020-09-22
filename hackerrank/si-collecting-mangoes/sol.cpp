#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#define ll long long

using namespace std;
// Alternatively you can use two stacks. 
// 1 to maintain the mangoes and the other to store the max value;
int main(){
    int t, c = 1;
    char ch;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++)
    {
        printf("Case %d:\n", i);
        ll n, max = 0, ip;
        stack<ll> mango;
        scanf("%lld", &n);

        while (n--)
        {
            scanf(" %c", &ch);
            switch (ch)
            {
            case 'A':
                scanf("%lld", &ip);
                if (ip > max)
                    max = ip;
                mango.push(max);
                break;

            case 'Q':
                if (mango.empty())
                {
                    max = 0;
                    printf("Empty\n");
                }
                else
                {
                    printf("%lld\n", mango.top());
                }
                break;

            case 'R':
                if (!mango.empty())
                {
                    mango.pop();
                    if (!mango.empty())
                    {
                        if (mango.top() < max)
                            max = mango.top();
                    }
                    else
                    {
                        max = 0;
                    }
                }
                break;

            default:
                break;
            }
        }
        

    }
    

    return 0;
}