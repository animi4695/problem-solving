#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool solve(string a, string b){
    if(a.length() > b.length()) return false;
    // 2-ptr approach
    // IDEA - take 2 ptr ptr1 for a and ptr2 for b. move the ptr2 when they are not equal. if they are equal move both.
    int n = a.length(), m = b.length();
    int ptr2 = 0, ptr1 = 0;
    while(ptr2 != m && ptr1 < n){
        if(a[ptr1] == b[ptr2]){
            ptr1++;
        }
        ptr2++;
    }
    if(n == ptr1) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        bool res = solve(a,b);
        if(res == true) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
    return 0;
}