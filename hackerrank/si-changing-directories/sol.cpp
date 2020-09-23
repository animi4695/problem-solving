#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
#include <string>
#include <queue>

using namespace std;
void processd(string &s){
    int i;
    while (i = s.find("..") != string::npos)
    {
        int j = s.rfind("/", i-2);
        s.erase(j, i-j+2);
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string cur = "";
        string in, d;
        while (n--)
        {
            cin>>in;
            if(in.compare("pwd") == 0) cout<<cur<<"/\n";
            else {
                cin>>d;
                if(d[0] == '/'){
                    cur = "";
                    d.erase(0,1);
                }
                while(d.find('/') != string::npos){
                    if(d.substr(0, d.find('/')) == ".."){
                        cur.erase(cur.rfind('/'));
                    }
                    else{
                        cur += "/" + d.substr(0, d.find('/'));
                    }
                    d.erase(0,1+d.find('/'));
                }
                if (d == ".."){
                    cur.erase(cur.rfind('/'));
                }
                else{
                    cur += "/" + d;
                }
            }
        }
        
    }
    return 0;
}