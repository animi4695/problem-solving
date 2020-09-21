#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
bool isPalindrome(char str[], int n){
    int p1 = 0, p2 = 0;
    if(n%2 == 0){
        // even length
        p1 = (n/2)-1;
        p2 = (n/2);
    }
    else{
        // odd length
        p1 =(n/2)-1;
        p2 = (n/2)+1;
    }
    while(p1 >= 0 && p2 < n){
            if(str[p1] != str[p2]){
                return false;
            }
            p1--;
            p2++;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        char str[n];
        for(int i = 0; i <n; i++){
            cin>>str[i];
        }
        if(isPalindrome(str,n)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
    return 0;
}