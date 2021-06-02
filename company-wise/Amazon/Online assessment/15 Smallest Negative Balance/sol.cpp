#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

map<string, int> mp;
vector<string> smallestNegativeBalance(vector<vector<string>> debts){
    for(auto list : debts){
        string borrower = list[0];
        string lender = list[1];
        int amount = stoi(list[2]);
        if(mp.find(borrower) == mp.end()){
            mp[borrower] = 0;
        }
        mp[borrower] -= amount;

        if(mp.find(lender) == mp.end()){
            mp[lender] = 0;
        }
        mp[lender] += amount;
    }

    auto custComp = [](string a, string b) {
        return mp[a] == mp[b] ? a > b : mp[a] < mp[b];
    };
    priority_queue<string, vector<string>, decltype(custComp)> pq(custComp);
    for(auto key : mp){
        pq.push(key.first);
    }

    vector<string> res;
    int min = 0;
    while(!pq.empty()){
        string person = pq.top();
        pq.pop();
        if(min >= mp[person]){
            min = mp[person];
            res.push_back(person);
        }
    }
    if(res.size() >= 1)
        return res;
    res.push_back("No One is in Debt");
    return res;
}

int main(){
    vector<vector<string>> debts = { {"Alex" , "Blake", "2"}, {"Blake" , "Alex", "2"}, 
                    {"Casey" , "Alex", "5"}, {"Blake" , "Casey", "7"}, 
                        {"Alex" , "Blake", "4"}, {"Alex" , "Casey", "4"}};
    vector<string> res = smallestNegativeBalance(debts);
    for(auto s : res){
        cout<<s<<" ";
    }
}