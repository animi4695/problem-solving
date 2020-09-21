#include<iostream>
#include<limits>
#include<vector>
#include<unordered_map>

using namespace std;
vector<int> solve1(vector<int>& A);
vector<int> solve(vector<int>& A);

vector<int> solve1(vector<int>& A){
    // (prefixsum, index)
    unordered_map<int, int> ump;
    int k = 0, l = 0, prefixSum = 0;
    vector<int> result;

    ump.insert({0, -1});

    for(int i = 0; i < A.size(); i++){
        prefixSum += A[i];
        auto itr = ump.find(prefixSum);
        if(itr != ump.end()){
            if((i - ump[prefixSum]) > l-k){
                l = i;
                k = ump[prefixSum];
            }
        }
        else{
            ump.insert({prefixSum, i});
        }
    }

    for(int i = k+1; i <=l; i++){
        result.push_back(A[i]);
    }

    for(auto res : result){
        cout<<res<<" ";
    }

    return result;
}

vector<int> solve(vector<int>& A){
    int n = A.size();
    vector<int> result;
    int resultSize = 0;
    for(int i = 0 ; i < n; i++){
        int sum = 0;
        vector<int> temp;
        for(int j = i; j < n; j++){
            sum += A[j];
            temp.push_back(A[j]);
            if(sum == 0){
                if((j-i+1) > resultSize){
                    resultSize = j-i+1;
                    result = temp;
                }
            }
        }
    }
    for(auto res : result){
        cout<<res<<" ";
    }
    return result;
}
int main(){
    vector<int> A = { 1, 2, -2, 4, -4 }; // { 1 , 3 , -1 , 2 , -4 , 1};
    solve1(A);
    return 0;
}