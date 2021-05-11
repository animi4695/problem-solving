#include<iostream>
#include<climits>
#include<cmath>
#include<string>

using namespace std;
bool solve(string s){
    int goodyears = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){ 
            goodyears++;
            // check if chef can go to heaven
            float val = (float)goodyears/(i+1);
            // cout<<goodyears<<" "<<i+1<<" "<<val<<" ";
            if(val >= 0.50){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l;
        string s;
        cin>>s;
        bool isSuccess = solve(s);
        if(isSuccess){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}