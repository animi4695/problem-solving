#include<iostream>
#include<string>

using namespace std;
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        string origin;
        cin >>n>> origin;
        string activity;
        int total = 0;
        while (n--)
        {
            cin >> activity;
            if(activity == "CONTEST_WON"){
                int rank;
                cin >> rank;
                if(rank <=20){
                    total = total + 300 + 20 - rank;
                }
                else{
                    total = total + 300;
                }
            }
            else if(activity == "TOP_CONTRIBUTOR"){
                total = total + 300;
            }
            else if(activity == "BUG_FOUND"){
                int severity = 0;
                cin >> severity;
                total = total + severity;
            }
            else if(activity == "CONTEST_HOSTED"){
                total = total + 50;
            }
        }
        // cout << total;
        if(origin == "INDIAN"){
            cout << total/200 << endl;
        }
        else{
            cout << total/400 << endl;
        }
        
    }
    return 0;
}