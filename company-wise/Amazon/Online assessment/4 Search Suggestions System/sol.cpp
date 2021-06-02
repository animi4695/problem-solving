#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

}

class Solution {
public:
    struct Trie {
        Trie* c[26] = {NULL};
        bool isEnd = false;
    };

    vector<vector<string>> suggestedProducts_sol2(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        for(int i = 0; i < searchWord.length(); i++){
            string x = searchWord.substr(0, i+1);
            vector<string> subAns;
            for(int j = 0; j < products.size(); j++){
                size_t found = products[j].find(x);
                if(found != string::npos && found == 0 && subAns.size() < 3)
                    subAns.push_back(products[j]);
            }
            res.push_back(subAns);
        }
        return res;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        for(auto product : products){
            insert(root, product);
        }

        vector<vector<string>> result;
        string prefix = "";
        for(auto ch : searchWord) {
            prefix += ch;
            result.push_back(search(root, prefix));
        }
        return result;
    }

    void insert(Trie* root, string p){
        Trie* node = root;
        for(auto ch : p){
            if(node->c[ch-'a'] == NULL){
                node->c[ch-'a'] = new Trie;
            }
            node = node->c[ch-'a'];
        }
        node->isEnd = true;
    }

    vector<string> search(Trie* root, string searchWord){
        vector<string> result;
        // move the root to end of searchWord
        Trie* node = root;
        for(auto ch : searchWord){
            int idx = ch-'a';
            if(node->c[idx] == NULL)
                return {};
            node = node->c[idx];
        }
        dfs(node, searchWord, result);
        return result;
    }

    void dfs(Trie* node, string prefix, vector<string>& result){
        if(result.size() == 3)
            return;
        if(node->isEnd)
            result.push_back(prefix);
        for(int i = 0; i < 26; i++){
            if(node->c[i])
                dfs(node->c[i], prefix + (char)(i + 'a'), result);
        }
    }
};