#include<iostream>
#include<string>
#include<map>
#include<unordered_map>

// Two ways to solve this prob is to use map<string,string> or unordered_map<string, string>
// In map, the strings are ordered, so lexicographical order is by-default in place.
// In Unordered map, the string are unordered, so we have to find the lexicographical order on our own.
// But Unordered map runs faster over map
using namespace std;
int main(){
    int n,m;

    cin>>n>>m;
    unordered_map<string, string> cc; // chefname - chefcountry
    unordered_map<string, int> v; // chefname - chefvotecount
    unordered_map<string, int> X; // countryname - countryvotecount
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin>>a>>b;
        cc.insert({a,b});
        v[a] = 0;
        X[b] = 0;
    }

    for(int i = 0 ; i <m ; i++){
        string a;
        cin>>a;
        v[a]++;
    }

    int max_ele = 0;
    string chef;
    string country;
    for(auto x: v){

        for(int j = 0; j< x.second; j++){
            X[cc[x.first]]++;
        }
        if(x.second > max_ele){
            max_ele = x.second;
            chef = x.first;
        }
        else if(x.second == max_ele){
            chef = chef>x.first? x.first : chef;
        }
    }

    max_ele = 0;
    for(auto y : X){
        if(y.second>max_ele){
            max_ele = y.second;
            country = y.first;
        }
        else if(y.second == max_ele){
            country = country>y.first? y.first : country;
        }
    }

    cout<<country<<endl<<chef<<endl;

    return 0;
}