#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

const long long MOD = 1e9+7;

int nchoc(int A, vector<int> &B) {
    priority_queue<int> pq(B.begin(), B.end());
    long long res = 0;
    for(int i = 0; i < A; i++){
        long long temp = pq.top();
        res += temp;
        res %= MOD;
        pq.pop();
        pq.push(floor(temp/2));
    }
    return res;
}
int main(){
    return 0;
}