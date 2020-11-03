#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,N;
    cin>>T;
    for(int i =0 ;i < T; i++){
        cin>>N;
        string dishes[N];
        for(int j=0;j < N; j++){
            cin>>dishes[j];
        }
        bool Main_arr[26];
        memset(Main_arr,true,sizeof(Main_arr));
        for(int j =0;j<N;j++){
            bool Second_arr[26] = {false};
            for(int k =0 ;dishes[j][k];k++){
                if(Main_arr[dishes[j][k] - 'a']){
                    Second_arr[dishes[j][k] - 'a'] = true;
                }
            }
            memcpy(Main_arr, Second_arr, 26);
        }
        int count = 0;
        for(int j = 0 ; j <26;j++){
            if(Main_arr[j])
                count++;
        }
        cout<<count<<"\n";
    }
}
