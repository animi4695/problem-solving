#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

vector<string> removeAnagram(vector<string> textList);
int main(){
    vector<string> textList = {"code", "doce", "ecod", "framer", "frame"};
    // Expected output = {"code", "frame", "framer"}
    vector<string> res = removeAnagram(textList);
    for(auto ele : res){
        cout<<ele<<" ";
    }
    return 0;
}

vector<string> removeAnagram(vector<string> textList) {
    vector<string> res;
    unordered_set<string> uniqueValues;

    for(auto text : textList) {
        string temp = text;
        sort(temp.begin(), temp.end());
        if(uniqueValues.find(temp) == uniqueValues.end()) {
            res.push_back(text);
            uniqueValues.insert(temp);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

