#include<iostream>
#include<string>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int count = 0;
        for(int i = 0; i< s.length()-1 ; i++){
            if(s[i] != s[i+1]){
                count++;
                i = i+1;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}