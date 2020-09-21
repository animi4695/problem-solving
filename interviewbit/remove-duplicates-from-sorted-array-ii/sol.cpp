#include<iostream>
#include<climits>
#include<vector>

using namespace std;
int removeDuplicates2(vector<int> &A){
    int ptr = 0, n = A.size();
    for(int i = 0 ; i < n; i++){
        if(i < n-2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
        else{
            A[ptr] = A[i];
            ptr++;
        }
    }

    return ptr+1;
}

int removeDuplicates(vector<int> &A){
    if(A.size() <= 2) return A.size();

    int p1 = 1;
    int p2 = 2; // current ele

    while(p2 < A.size()){
        if(A[p1] == A[p2] && A[p2] == A[p1-1]){
            p2++;
        }
        else{
            p1++;
            p2++;
            A[p1] = A[p2];
        }
    }

    return p1+1;
}

int main(){
    vector<int> A= {1,1,1,2,2,2};
    cout<<removeDuplicates2(A);
    return 0;
}