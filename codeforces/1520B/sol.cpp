#include<iostream>
#include <limits>
#include<vector>
#include<string>
#include<algorithm>
#include <fstream>

using namespace std;

int countDigits(int n){
    string str = to_string(n);
    return str.length();
}

long long solve(int n){
    int len = countDigits(n);
    long long ans = 0;
    long long temp = 0;
    for(int i = 0; i < len; i++){
        temp = temp*10 + 1;
        for(int j = 1; j <= 9; j++){
            if(temp*j <= n){
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    // ofstream MyFile("output.txt");
    // for(int i = 1; i <= 10000; i++){
    //     // cout<<solve(i)<<"\n";
    //     MyFile << solve(i);
    //     MyFile << " " << i;
    //     MyFile << "\n";
    // }
    // MyFile.close();
    
    return 0;
}