#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string myA;
        cin>>myA;
        string res = "";
        if(myA[0] == '1'){
            res = "10";
        }
        else{
            res = "1";
            res += myA[0];
        }
        for(int i = 1; i < myA.length(); i++){
            res += myA[i];
        }
        cout<<res<<"\n";
    }
    return 0;
}