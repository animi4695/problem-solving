#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class MedianFinder {
    priority_queue<int> L; // maxHeap
    priority_queue<int, vector<int>, greater<int> > R; // minHeap

public:
   void addNum(int num){
       L.push(num);
       R.push(L.top());
       L.pop();

       if(L.size() < R.size()){
           L.push(R.top());
           R.pop();
       }
   }

   int getMedian(){
       return L.top();
   }
};

void solve(vector<int>& arr, int n){
    MedianFinder medianFinder;
    for(int i = 0; i < n; i++){
        medianFinder.addNum(arr[i]);
        cout<<medianFinder.getMedian()<<" ";
    }
}


int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];
        solve(arr, n);
        cout<<"\n";
    }
    
    return 0;
}