#include<iostream>
#include <limits>
#include<vector>

using namespace std;
void merge(vector<int>& A, vector<int>& B);

void merge(vector<int>& A, vector<int>& B){
    int m = A.size();
    int n = B.size();
    A.resize(m+n);
    // two pointer techinque
    int p1 = m-1, p2 = n-1, temp = m+n-1;
    while(p2 >= 0){
        if(p1 >= 0 && A[p1] > B[p2]){
            A[temp--] = A[p1--];
        }
        else{
            A[temp--] = B[p2--];
        }
    }
}

int main(){

    vector<int> A = {3,8,10,18,25};
    vector<int> B = {-2,1,5,9,11,13,14};

    merge(A,B);
    return 0;
}