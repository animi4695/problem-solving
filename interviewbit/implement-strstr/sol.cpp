#include<iostream>
#include<climits>

using namespace std;
int strStr(const string A, const string B){
    int index = -1;
    // edge cases
    if(A.empty() || B.empty()) return index;

    for(auto i = 0; i < A.length(); ++i){
        // check for first char in B.
        if(A[i] == B[0]){
            // check for remaining chars
            int index = i;
            // j keeps track for the numbers of chars in B which are equal to A
            int j = 0;
            while(j < B.length()){
                if(B[j] == A[i] && i < A.length()){
                    ++i;
                    ++j;
                }
                else{
                    // not equal, so break properly
                    index = -1;
                    i = i - j;
                    break;
                }
            }
            if(j==B.length()){
                // found str
                return index;
            }
        }
    }
    return index;
}
int main(){
    string A,B;
    getline(cin, A);
    getline(cin, B);
    cout<<strStr(A,B)<<"\n";
    return 0;
}