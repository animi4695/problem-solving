#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string tag;
        cin>>tag;
        bool flag = false;
        if(tag.length() < 4 || tag[0] != '<' || tag[1] != '/' || tag[tag.length()-1] != '>'){
            flag = true;
        }
        else{
            for(int i = 2; i < tag.length()-1; i++){
                if(!isalnum(tag[i]) || isupper(tag[i])){
                    flag = true;
                    break;
                }
            }
        }

        if (flag == true)
            cout << "Error\n";
        else
        {
            cout << "Success\n";
        }
    }
    return 0;
}