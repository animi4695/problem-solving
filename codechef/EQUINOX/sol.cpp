#include<iostream>
#include<climits>
#include<cmath>
#include<string>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, a, b;
        cin>>n>>a>>b;
        long long p1 = 0, p2 = 0;
        while (n--)
        {
            string str;
            cin>>str;
            // EQUINOX
            if(str[0] == 'E' || str[0] == 'Q' || str[0] == 'U' || str[0] == 'I' || str[0] == 'N' || str[0] == 'O' || str[0] == 'X'){
                p1 += a;
            }
            else
            {
                p2 += b;
            }
        }
        if(p1 == p2){
            cout<<"DRAW\n";
        }
        else if(p1 > p2){
            cout<<"SARTHAK\n";
        }
        else{
            cout<<"ANURADHA\n";
        }
    }
    return 0;
}