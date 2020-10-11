#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main(){
    int t;
    cin>>t;
    bool isWin[100001];
    for (int state = 0; state <= 100001; ++state) {
        isWin[state] = false;
        for (int i = 1; i*i <= state; ++i) {
            int perfectSquare = i*i;
            if (!isWin[state - perfectSquare]) {
                isWin[state] = true;
                break;
            }
        }
    }
    while (t--)
    {
        int n;
        cin>>n;
        (isWin[n] == true) ? cout<<"Win\n" : cout<<"Lose\n";
    }
    
    return 0;
}