#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
#include <string>

using namespace std;

vector<string> helper(string input){
    vector<string> configs;
    string temp = "";
    
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '|'){
            configs.push_back(temp);
            temp = "";
        } else {
            temp += input[i];
        }
    }
    configs.push_back(temp);
    
    map<int, string> mp;
    
    for(auto configuration : configs){
        int ordinal_idx = stoi(configuration.substr(0, 4));
        string config = configuration.substr(4);
        if(ordinal_idx == 0 || mp.find(ordinal_idx) != mp.end()){
            return {"invalid configuration"};
        }

        if(config.length() != 10 || (!isalnum(config[0]) || !isalnum(config[1]) ||  !isalnum(config[2]) || !isalnum(config[3]) || !isalnum(config[4]) || !isalnum(config[5]) || !isalnum(config[6]) || !isalnum(config[7]) || !isalnum(config[8]) || !isalnum(config[9]))){
            return {"invalid configuration"};
        }

        mp[ordinal_idx] = config;
    }

    if(mp.size() != configs.size()){
        return {"invalid configuration"};
    }

    vector<string> res;
    for(auto it : mp){
        res.push_back(it.second);
    }
    return res;
}

int main(){
    // string input = "0001LAJ5KBX9H8|0003UKURNK403F|0002MO6K1Z9WFA|0004OWRXZFMS2C";    // valid configuration
    // string input = "0002f7c22e7904|000176a3a4d214|000205d29f4a4b";       // valid configuration
    string input = "0002f7c22e7904|000176a3a4d214|000305d29f4a4b";  // invalid configuration
    vector<string> res;
    res = helper(input);
    for(auto r : res){
        cout<<r<<endl;
    }
    return 0;
}