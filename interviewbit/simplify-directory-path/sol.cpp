#include<iostream>
#include<climits>
#include<stack>
#include<vector>

using namespace std;
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

string solve(string A){
    vector<string> st;
    vector<string> components = split(A, "/");
    for(string dir : components){
        if(dir == "." || dir.empty()) continue;
        else if(dir == ".."){
            if(!st.empty()) st.pop_back();
        }
        else{
            st.push_back(dir);
        }
    }

    string res = "";
    for(auto str : st){
        res.append("/");
        res.append(str);
    }
    return res.length() > 0 ? res : "/";
}

int main(){
    string A = "///";
    solve(A);
    return 0;
}