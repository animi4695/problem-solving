#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct CustType{
    int at, ct;
};

struct cmp{
    bool operator()( CustType& a, CustType& b){
        return a.ct > b.ct;
    }
};

bool operator < (CustType a, CustType b){
    return a.at<b.at;
}

vector<CustType> c;
priority_queue<CustType, vector<CustType>, cmp> pq;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        CustType cust;
        cin>>cust.at>>cust.ct;
        c.push_back(cust);
    }

    sort(c.begin(), c.end());

    long long curr_t = 0;
    long long tot = 0;
    int idx = 0;

    while(true){

        if(idx == n && pq.empty()) break;

        int i;
        for(i = idx; i < n; i++){
            if(c[i].at <= curr_t){
                pq.push(c[i]);
            }
            else{
                idx = i;
                break;
            }
        }

        // we don't know how the above for loop exited, so if i reaches 
        // end of for loop, then idx will be n;
        if(i == n) idx == n;

        if(!pq.empty()){
            CustType cust = pq.top();
            pq.pop();

            tot += curr_t - cust.at + cust.ct;
            curr_t += cust.ct;
        }
        else{
            if(idx != n) curr_t = c[idx].at;
        }
    }

    cout<<tot/n<<"\n";

    return 0;
}