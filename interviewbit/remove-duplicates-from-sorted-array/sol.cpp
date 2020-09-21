#include<iostream>
#include<climits>
#include<vector>

using namespace std;

// simplified, which helps in removeDuplicates from sorted array-II
int removeDuplicates2(vector<int> &A){
    int ptr = 0, n = A.size();
    for(int i =0; i < n; i++){
        if(i < n-1 && A[i] == A[i+1]) continue;
        else{
            A[ptr] = A[i];
            ptr++;
        }
    }

    return ptr;
}

int removeDuplicates(vector<int> &A){
    if( A.size() <= 1){
        return A.size();
    }
    int ptr = 0;

    for(int i = 1; i < A.size(); i++){
        if(A[ptr] != A[i]){
            A[ptr+1] = A[i];
            ptr++;
        }
    }

    // its optional to delete space
    A.erase(A.begin()+ptr+1, A.end());
    // cout<<ptr+1;
    return ptr+1;
}

int main(){
    vector<int> A = {1,1,2};
    removeDuplicates(A);
    return 0;
}