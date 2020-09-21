#include<iostream>
#include <limits>

using namespace std;
int main(){
    int A[] = { 1,2,2,3,1};

    int result = 0;
    for(auto a: A){
        result ^= a;
    }
    cout<<result;
    return result;
}