#include<iostream>
#include <limits>
#include<unordered_set>

using namespace std;

int colorful(int A){
    string a = to_string(A);
    unordered_set<int> mySet;
    for(int i = 0 ; i < a.length(); i++){
        int product = 1;
        for(int j = i; j < a.length(); j++){
            product *= (a[j]-'0');

            if(mySet.find(product) != mySet.end()){
                return 0;
            }
            mySet.insert(product);
        }
    }
    return 1;
}

int main(){
    int A;
    cin>>A;
    cout<<colorful(A);
    return 0;
}