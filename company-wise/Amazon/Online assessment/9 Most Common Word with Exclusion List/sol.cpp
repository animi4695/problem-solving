#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    map<string, int> umap;
    paragraph.push_back(' ');

    // find freq of each word in paragraph
    for(int i = 0; i < paragraph.size(); i++){
        string word = "";
        while (isalpha(paragraph[i]))
        {
            word += tolower(paragraph[i]);
            i++;
        }
        if(!word.empty())
            umap[word]++;
    }

    // Remove banned words from the frequency, umap
    for(auto& word: banned){
        if(umap.find(word) != umap.end()){
            umap.erase(word);
        }
    }

    string ans;
    int maxFreq = INT32_MIN;
    for(auto mp : umap){
        if(maxFreq < mp.second){
            ans = mp.first;
            maxFreq = mp.second;
        }
    }
    return ans;
}

int main() {
    string paragraph  = "If this book was written today in the midst of the slew of dystopian novels that come out, it may not have stood out. But, this book was way ahead of its time.";
    vector<string> banned = {"of", "was", "the"};

    string res = mostCommonWord(paragraph, banned);
    cout<<res;

}

