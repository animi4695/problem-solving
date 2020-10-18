#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int> res;
    int count = 0;
    if(B > n) return res;
    unordered_map<int, int> ump;
    
    // 1st window
    for(int i = 0; i < B; i++) {
        if(ump[A[i]] == 0) count++;
        ump[A[i]]++;
    }
    res.push_back(count);
    
    for(int i = B; i < n; i++){
        if(ump[A[i-B]] == 1) --count;
        ump[A[i-B]]--;
        
        if(ump[A[i]] ==  0) count++;
        ump[A[i]]++;
        
        res.push_back(count);
    }
    return res;
}

int main(){
    return 0;
}