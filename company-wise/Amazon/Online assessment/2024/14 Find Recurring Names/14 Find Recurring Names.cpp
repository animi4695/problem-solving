#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
vector<string> findRecurringNames(vector<string>& realNames, vector<string>& allNames);

int main() {
    vector<string> realNames = {"rohn", "henry", "daisy"};
    vector<string> allNames = {"ryhen", "aisyd", "henry"};

    vector<string> res = findRecurringNames(realNames, allNames);
    for(auto r : res){
        cout << r << " ";
    }

    cout<<"\n";

    realNames = {"tom", "jerry"};
    allNames = {"reyjr", "mot", "tom", "jerry", "mto"};

     res = findRecurringNames(realNames, allNames);
    for(auto r : res){
        cout << r << " ";
    }

    return 0;
}

vector<string> findRecurringNames(vector<string>& realNames, vector<string>& allNames) {
    vector<string> res;
    unordered_map<string, int> allNamesCount;

    // count occurrences of names in allNames
    for(auto name : allNames){
        string sortedName = name;
        sort(sortedName.begin(), sortedName.end());
        allNamesCount[sortedName]++;
    }

    // map sorted realName to realName
    unordered_map<string, string> realNamesMap;
    for(auto name: realNames){
        string sortedRealName = name;
        sort(sortedRealName.begin(), sortedRealName.end());
        realNamesMap[sortedRealName] = name;
    }

    // find res. every allNamesCount record with frequency > 1 should be part of our result.
    for(auto name : allNamesCount){
        if(name.second > 1){
            res.push_back(realNamesMap[name.first]);
        }
    }

    if(res.empty()){
        return {"None"};
    }

    sort(res.begin(), res.end());

    return res;
}