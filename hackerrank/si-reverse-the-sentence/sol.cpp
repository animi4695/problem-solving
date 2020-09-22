#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
void solve(string a){
    int p1 = 0;
    int p2 = a.length()-1;
    while (p1 < p2)
    {
        char temp = a[p1];
        a[p1] = a[p2];
        a[p2] = temp;
        p1++;
        p2--;
    }
    cout<<a;
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while (t--)
    {
        string a;
        getline(cin, a);
        solve(a);
    }
    
    return 0;
}