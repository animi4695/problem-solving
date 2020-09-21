#include<iostream>
#include<climits>
#include<vector>

using namespace std;
string longestCommonPrefix(vector<string> &A){
    string result = "";
    if(A.size() <= 0) return result;
    int n = A.size();
    // try and find the least len string among A
    int index = INT_MAX;
    for(int i = 0; i<n; i++){
        if(index > A[i].length()){
            index = A[i].length();
        }
    }

    for(int i = 0; i < index; i++){
        auto temp = A[0][i];
        int k = 1;
        while(k < n){
            if(temp == A[k][i]){
                ++k;
            }
            else{
                return result;
            }
        }
        result += temp;
    }
    return result;
}
int main(){
    vector<string> A = { "abcdefgh", "aefghijk", "abcefgh"};
    cout<<longestCommonPrefix(A);
    return 0;
}