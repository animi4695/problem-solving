#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;
vector<string> splitStr(string str);
vector<string> GetMostSoughtToysCount(int numOfToys,int toptoys,vector<string>& toys,int numOfQuotes,vector<string>& quotes);
struct custCompator;

map<string, int> countToyMentions;
map<string, int> countToyMentionsDistinctReviews;
int main(){
    int numOfToys = 6;
    int toptoys = 8;
    vector<string> toys =  {"elmo", "elsa", "legos", "drone", "tablet", "warcraft"};
    int numOfQuotes = 2;
    vector<string> quotes = {"Emo is the hottest of the season! Elmo will be on every kid's wishlist!",
        "The new Elmo dolls are super high quality",
        "Expect the Elsa dolls to be very popular this year",
        "Elsa and Elmo are the toys I'll be buying for my kids",
        "For parents of older kids, look into buying them a drone",
        "Warcraft is slowly rising in popularity ahead of the holiday season"
        };

    vector<string> res = GetMostSoughtToysCount(numOfToys, toptoys, toys, numOfQuotes, quotes);
    for(auto s: res){
        cout<<s<<" ";
    }
}

vector<string> GetMostSoughtToysCount(int numOfToys,int toptoys,vector<string>& toys,int numOfQuotes,vector<string>& quotes){
    vector<string> topKToys;
    for(auto toy : toys){
        countToyMentions[toy] = 0;
    }

    for(auto quote : quotes){
        transform(quote.begin(), quote.end(), quote.begin(), ::tolower);
        vector<string> quoteWords = splitStr(quote);
        for(auto quoteWord : quoteWords){
            transform(quoteWord.begin(), quoteWord.end(), quoteWord.begin(), ::tolower);
            if(countToyMentions.find(quoteWord) != countToyMentions.end()){
                countToyMentions[quoteWord]++;
            }
        }
    }

    vector<pair<string, int>>V(countToyMentions.begin(), countToyMentions.end());
    sort(V.begin(), V.end(), [](auto a, auto b) {        
        if(a.second == b.second)
            return a.first < b.first; 
        return a.second > b.second;
    });
    int i = 0;
    int count = toptoys > V.size() ? V.size() : toptoys;
    while(count--){
        topKToys.push_back(V[i].first);
        i++;
    }
    return topKToys;
}

vector<string> splitStr(string str){
    vector<string> res;
    string word;
    for(auto ch : str){
        if(ch == ' '){
            res.push_back(word);
            word = "";
        }
        else{
            word = word + ch;
        }
    }
    if(word != ""){
        res.push_back(word);
    }
    return res;
}