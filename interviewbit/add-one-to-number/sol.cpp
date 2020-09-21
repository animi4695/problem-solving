#include<iostream>
#include <limits>
#include<vector>

using namespace std;
vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    vector<int> result;
    int carry = 0;
    result.push_back((1+A[n-1])%10);
    carry = (1+A[n-1])/10;

    for (int i = n-2; i >= 0; i--)
    {
        result.push_back((carry + A[i])%10);
        carry = (carry + A[i])/10;
    }

    if(carry){
        result.push_back(carry);
    }

    int x = result.size();
    for(int i=0; i< x/2; i++){
        swap(result[i], result[x-i-1]);
    }

    while (result[0] == 0)
    {
        result.erase(result.begin());
    }

    // for(auto c : result) cout<<c<<" ";
    return result;
}

int main(){
    vector<int> A = { 6, 4, 7, 7, 8, 9};
    plusOne(A);
    return 0;
}