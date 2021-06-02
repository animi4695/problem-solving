#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int>> findPairs(vector<int> FTasks, vector<int> BTasks, int k);

int main() {
    vector<int> FTasks = {1, 7, 2, 4, 5, 6};
    vector<int> BTasks = {1, 1, 2};
    int k = 10;
    vector<vector<int>> res = findPairs(FTasks, BTasks, k);
    for(auto r : res){
        cout<<r[0]<<" "<<r[1]<<"\n";
    }
}


vector<vector<int>> findPairs(vector<int> FTasks, vector<int> BTasks, int k){
    vector<vector<int>> res;
    map<int, vector<int>> FMemToIds;
    int maxMem = 0;
    for(int i = 0; i < FTasks.size(); ++i){
        int mem = FTasks[i];
        if(mem > k)
            continue;
        if(maxMem < mem)
            maxMem = mem;
        FMemToIds[mem].push_back(i);
    }

    for(auto Ftask : FMemToIds[maxMem]){
        res.push_back({Ftask, -1});
    }

    sort(FTasks.begin(), FTasks.end());

    for(int i = 0; i < BTasks.size(); i++){
        int BMem = BTasks[i];
        int FMem = *(lower_bound(FTasks.begin(), FTasks.end(), k-BMem));
        // if(FMem == NULL)
        //     continue;
        int SumMem = FMem + BMem;
        if(SumMem > k || SumMem < maxMem)
            continue;

        if(SumMem > maxMem){
            res = {};
            maxMem = SumMem;
        }

        for(int id : FMemToIds[FMem]){
            res.push_back({id, i});
        }
    }
    return res;
}