#include <iostream>
#include <string>

#define MAX 1001

using namespace std;
int main()
{
    int t;
    string str;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int strleft[26] = {};
        int strright[26] = {};
        // getline(cin, str);
        cin >> str;
        // cout << str;
        if (str.length() % 2 == 0)
        {
            // cout << "Even" << str.length() << "-";
            for (int i = 0; i < (str.length() / 2); i++)
            {
                // cout <<"MMMM";
                strleft[str[i] - 97] = strleft[str[i] - 97] + 1;
            }
            for (int i = str.length() / 2; i < str.length(); i++)
            {
                strright[str[i] - 97] = strright[str[i] - 97] + 1;
            }
        }
        else
        {
            // cout << "Odd" << str.length() << endl;
            for (int i = 0; i < (str.length() / 2); i++)
            {
                strleft[str[i] - 97] = strleft[str[i] - 97] + 1;
            }
            for (int i = (str.length() / 2) + 1; i < str.length(); i++)
            {
                strright[str[i] - 97] = strright[str[i] - 97] + 1;
            }
        }
        bool isLapin = true;
        for (int i = 0; i <= 25; i++)
        {
            // cout << i << "-" << strright[i] << "-" << strleft[i] << endl;
            if (strright[i] != strleft[i])
            {
                isLapin = false;
                // break;
            }
        }
        if (isLapin)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}