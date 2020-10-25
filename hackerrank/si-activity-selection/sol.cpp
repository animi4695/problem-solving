#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pd;
struct mycmp{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return b.second < a.second;
    }
};

int solve(vector<int> &stime, vector<int> &ftime, int n){
    int res = 1;
    int i = 0;
    for(int j = 1; j < n; j++){
        if(stime[j] >= ftime[i]){
            res++;
            i = j;
        }
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
        vector<int> stime(n);
        vector<int> ftime(n);
        for(int i = 0; i < n; i ++) cin>>stime[i];
        for(int i = 0; i < n; i ++) cin>>ftime[i];

        // ascending order by finish times. so We use min heap with custom comparator 
        priority_queue<pd, vector<pd>, mycmp> pq;
        for(int i = 0; i < n; i++){
            pq.push({stime[i], ftime[i]});
        }

        int i = 0;
        while(!pq.empty()){
            stime[i] = pq.top().first;
            ftime[i] = pq.top().second;
            i++;
            pq.pop();
        }

        cout<<solve(stime, ftime, n)<<"\n";
    }
    
    return 0;
}