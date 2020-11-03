#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arrA(n);
        vector<int> arrB(n);
        int ans = 0;
        for(int i = 0; i<n;i++){
            cin>>arrA[i];
        }
        for(int i = 0; i<n;i++){
            cin>>arrB[i];
        }

        if(arrA.size() <= 1 || arrB.size() <=1){
            cout<<-1;
            continue;
        }

        sort(arrA.begin(), arrA.end());
        sort(arrB.begin(), arrB.end());

        if(arrA == arrB){
            cout<<0;
            continue;
        }
        cout<<1;
    }
    
    return 0;
}