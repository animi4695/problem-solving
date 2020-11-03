#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, p;
        cin >> s;
        cin >> p;
        map<char, int> sfreq;
        map<char, int> tempfreq;

        for (auto ch : s)
            sfreq[ch]++;

        string res = "";
        for (auto ch : p)
        {
            sfreq[ch]--;
        }

        tempfreq = sfreq;
        string temp = "";
        for(auto ch: tempfreq){
            if(ch.first >= p[0]){
                break;
            }
            else{
                while (tempfreq[ch.first]> 0)
                {
                    temp += ch.first;
                    tempfreq[ch.first]--;
                }
            }
        }

        temp += p;

        for(auto ch : tempfreq){
            while(tempfreq[ch.first] > 0){
                temp += ch.first;
                tempfreq[ch.first]--;
            }
        }

        for(auto ch: sfreq){
            if(ch.first > p[0]){
                break;
            }
            else{
                while (sfreq[ch.first]> 0)
                {
                    res += ch.first;
                    sfreq[ch.first]--;
                }
            }
        }

        res += p;

        for(auto ch : sfreq){
            while(sfreq[ch.first] > 0){
                res += ch.first;
                sfreq[ch.first]--;
            }
        }
       
        cout << min(res,temp) << "\n";
    }

    return 0;
}