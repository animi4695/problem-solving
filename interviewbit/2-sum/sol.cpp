#include<iostream>
#include <limits>
#include<vector>
#include<map>

using namespace std;
vector<int> twoSum(const vector<int>& A, int B){
    int n = A.size();

    // store arr value and index
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int k = B - A[i];

        auto itr = mp.find(k);
        if(itr != mp.end()){
            cout<<mp[k]<<" "<<i+1;
            return {mp[k], i+1};
        }
        else{
            if(!mp[A[i]])  mp[A[i]] = i+1;
        }
    }
    return {};
}

int main(){
    vector<int> A = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 };
    int B = -3;
    twoSum(A, B);
    return 0;
}