#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

struct product {
    int pn;
    int pd;
    double rating;
    double increasing;
    product(int pn, int pd){
        pn = pn; 
        pd = pd;
        rating = (double)(pn/pd);
        increasing = (double)(pn+1)/(pd+1);
    }
};

struct myComp {
    bool operator()(product p1, product p2){
        return p1.increasing > p2.increasing;
    }
};


int five_star_reviews(vector<vector<int>>& ratings, int threshold) {
    int res = 0;
    int n = ratings.size();
    priority_queue<product, vector<product>, myComp> pq;
    double currSum = 0;
    for(auto r : ratings){
        pq.push(product(r[0], r[1]));
        currSum += r[0]/r[1];
    }

    double currThreshold = currSum/n;
    while(currThreshold*100 < threshold) {
        auto temp = pq.top();
        pq.pop();
        currThreshold += temp.increasing/n;
        temp = product(temp.pn+1, temp.pd+1);
        pq.push(temp);
        res++;
    }
    return res;
}


int main(){
    vector<vector<int>> ratings = { {4,4},{1,2},{3,6} };
    cout<<five_star_reviews(ratings, 77);
}