#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int solve(int arr[], int n){
    // Learning - This cannot be solved by sorting and taking the min value. Try for the testcase 
    // 1 2 3 4 5 expected o/p is 33
    // We have to solve greedily, every time we add, we have to make sure we are adding least/min values of array after adding them.

    // two get minimum every time. we can use min heap
    // In c++, by default Max heap is used by priority_queue
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr+n);
    int res = 0;
    while (pq.size() > 1)
    {
        int firstMin = pq.top();
        pq.pop();
        int secondMin = pq.top();
        pq.pop();

        res += firstMin + secondMin;
        pq.push(firstMin+secondMin);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        cout<<solve(arr, n)<<"\n";
    }
    
    return 0;
}