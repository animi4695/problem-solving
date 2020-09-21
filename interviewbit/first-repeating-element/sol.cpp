#include<iostream>
#include <limits>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int solve1(vector<int>& A){
    //using unordered_map
    unordered_map<int, int> ump;
    int min = -1;
    for(int i = A.size() ; i >= 0; i--){
        ump[A[i]]++;
        if(ump[A[i]] > 1) min = A[i];
    }

    return min;
}

int solve(vector<int>& A){
    // using set
    unordered_set<int> uset;
    int minIndex = -1;
    for(int i = A.size()-1 ; i >=0; i--){
        auto itr = uset.find(A[i]);
        if(itr != uset.end()){
            minIndex = i;
        }
        else{
            uset.insert(A[i]);
        }
    }
    return minIndex == -1 ? -1 : A[minIndex];
}

int main(){
    vector<int> A = { 10, 5, 3, 4, 3, 5, 6};
    cout<<solve1(A);
    return 0;
}