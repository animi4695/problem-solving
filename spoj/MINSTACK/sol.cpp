#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string a = "PUSH";
    string q = "POP";
    string r = "MIN";
    stack<int> s1;
    stack<int> s2;
    while (t--)
    {

        string s;
        cin >> s;
        if (s == a)
        {
            int n1;
            cin >> n1;
            s1.push(n1);
            if (s2.empty() || s1.top() <= s2.top())
            {
                s2.push(n1);
            }
        }
        else if (s == r)
        {
            if (!s2.empty())
            {
                cout << s2.top() << "\n\n";
            }
            else
            {
                cout << "EMPTY"
                     << "\n\n";
            }
        }
        else if (s == q)
        {
            if (!s1.empty())
            {
                if (!s2.empty() && s1.top() == s2.top())
                {
                    s1.pop();
                    s2.pop();
                }
                else
                {
                    s1.pop();
                }
            }
            else{
            	cout << "EMPTY"
                     << "\n\n";
            }
        }
    }

    return 0;
}