#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
string filter(string &str){
    string res;
    int i = 0;
    while(str[i]){
        if(str[i] != ' ') break;
        i++;
    }
    int j = str.length()-1;
    while(j >= 0){
        if(str[j] != ' ') break;
        j--;
    }
    return str.substr(i, j-i+1);
}

bool isVowel(char ch){
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')  return true;
    return false;
}

void solve(string &str){
    int vowels =0, words = 0, consonents = 0;
    string filtered_str = filter(str);
    if(filtered_str.empty()){
        cout<<"0 0 0\n";
        return;
    }
    char prev = ' ';
    for(int i = 0; i < filtered_str.length(); i++){
        if(filtered_str[i] == ' ' && prev != ' '){
            words++;
        }
        else if(filtered_str[i] != ' '){
            if (isVowel(filtered_str[i]))
            {
                vowels++;
            }
            else
            {
                consonents++;
            }
        }
        prev = filtered_str[i];
    }

    cout<<words+1<<" "<<vowels<<" "<<consonents<<"\n";
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin,str);
        solve(str);
    }
    
    return 0;
}