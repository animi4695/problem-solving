#include<iostream>
#include<climits>
#include<vector>


using namespace std;
int removeElement(vector<int> &A, int B){
    int ptr = 0;
    int n = A.size();
    for(int i = 0 ; i < n; i++){
        if(A[i] != B){
            A[ptr] = A[i];
            ptr++;
        }
    }
    // for(auto a : A) cout<<a<<" ";
    return ptr;
}

int main(){
    vector<int> A = {4, 1, 1, 2, 1, 3};
    int B = 4;
    removeElement(A, B);
    return 0;
} 