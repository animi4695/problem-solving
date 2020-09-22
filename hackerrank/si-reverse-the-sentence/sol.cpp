#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
string reverse(string a, int p1, int p2){
    while (p1 < p2){
        char temp = a[p1];
        a[p1] = a[p2];
        a[p2] = temp;
        p1++;
        p2--;
    }

    return a;
}
void solve(string a){
    int p1 = 0;
    int p2 = a.length()-1;
    // reverse complete sentence
    a = reverse(a, p1, p2);

    // reverse each word
    p1 = 0, p2 = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != ' '){
            p1 = i;
            p2 = i;
            while(i < a.length() && a[i] != ' '){
                i++;
            }
            p2 = i-1;
            a = reverse(a, p1, p2);
        }
    }
    cout<<a<<"\n";
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while (t--)
    {
        string a;
        getline(cin, a);
        solve(a);
    }
    
    return 0;
}