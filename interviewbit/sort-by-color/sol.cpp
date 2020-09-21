#include<iostream>
#include<climits>
#include<vector>

using namespace std;
void sortColors(vector<int> &A){
    // take a count arr of size 3;
    vector<int> count(3,0);

    for(auto a : A){
        count[a]++;
    }

    int ptr = 0;
    int i = 0;
    while(ptr <= 2){
        if(count[ptr] != 0){
            A[i] = ptr;
            count[ptr]--;
            i++;
        }
        else{
            ptr++;
        }
    }
    // for(auto a : A){
    //     cout<<a<<" ";
    // }
}

int main(){
    vector<int> A = { 0, 1, 2, 0, 1, 2};
    sortColors(A);
    return 0;
}