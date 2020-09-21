#include<iostream>
#include <limits>
#include<vector>
#include<algorithm>

using namespace std;

int pickingNumbers(vector<int>& a) {
    int res =0;
    int cnt[100] = {0};
    for(auto c : a){
        cnt[c]++;
    }

    // find frequency of all the numbers in the vector.
    // find which two consecutive numbers are occuring more than one and sum of those frequency will be the answer.

    for(int i = 0 ; i < a.size()-1; i++){
        if(cnt[i] + cnt[i+1] > res){
            res = cnt[i]+cnt[i+1];
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        vector<int> myvec = { 4, 6, 5, 3, 3, 1};
        pickingNumbers(myvec);
    }
    
    return 0;
}