#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int solve(priority_queue<int, vector<int>, greater<int>>pq, int k){
    int res = 0;
    while (pq.size() >= 2 && pq.top() < k){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int sweet = first + 2*second;
        pq.push(sweet);
        res++;
    }

    return (pq.top() >= k ? res : -1) ;
}

int main(){
    int n, k;
    cin>>n>>k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    cout<<solve(pq, k);
    return 0;
}