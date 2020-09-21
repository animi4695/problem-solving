#include<iostream>
#include<climits>
#include<vector>

using namespace std;
int diffPossible(vector<int> &A, int B){

    int n = A.size();
    int p1 = 0, p2 = 1;
    while(p1 < n && p2 < n){
        int diff = A[p2] - A[p1];
        if(diff == B && p1!=p2){
            return 1;
        }
        else if(diff < B){
            p2++;
        }
        else{
            p1++;
        }
    }
    return 0;
}

int main(){

    vector<int> A = { 1, 2, 2, 3, 4};
    int B = 0;

    cout<<diffPossible(A, B);
    return 0;
}