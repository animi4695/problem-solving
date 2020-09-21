#include<iostream>
#include <limits>
#include<vector>
#include<algorithm>

using namespace std;
void solve(vector<int>& arr,vector<int>& iparr, int idx, bool taken[]);
int cost(vector<int> A, vector<int> inpArr);
bool isMagicSquare(vector<int> ans);

int ans = INT32_MAX;
bool taken[10] = {false};
int cnt = 0;
void solve(vector<int>& arr,vector<int>& iparr, int idx, bool taken[]){
    if(idx == 9) {
        if(isMagicSquare(arr) == true){
            for(auto c : arr){
                cout<<c<<" ";
            }
            cnt++;
            cout<<cnt<<"\n";
            ans = min(ans, cost(arr, iparr));
            return;
        }
    }
    for(int i = 1; i <= 9; i++){
        if(taken[i] == false){
            taken[i] = true;
            arr[idx] = i;
            solve(arr, iparr, idx+1, taken);
            taken[i] = false;
        }
    }
}

int cost(vector<int> A, vector<int> inpArr){
    int c = 0;
    for(int i = 0 ; i < 9; i++){
        c += abs(A[i]-inpArr[i]);
    }
    return c;
}

bool isMagicSquare(vector<int> ans){
    if(ans[4] != 5) return false;

    // diagonal check
    if(ans[0] + ans[4] + ans[8] != 15) return false;
    if(ans[2] + ans[4] + ans[6] != 15) return false;

    // row check
    if(ans[0] + ans[1] + ans[2] != 15) return false;
    if(ans[3] + ans[4] + ans[5] != 15) return false;
    if(ans[6] + ans[7] + ans[8] != 15) return false;

    // col check
    if(ans[0] + ans[3] + ans[6] != 15) return false;
    if(ans[1] + ans[4] + ans[7] != 15) return false;
    if(ans[2] + ans[5] + ans[8] != 15) return false;

    return true;
}
int formingMagicSquare(vector<vector<int>> s) {
    int ROWS = s.size();
    int COLS = s[0].size();

    vector<int> arr(ROWS*COLS);

    for(int i = 0 ; i < ROWS; i++){
        for(int j = 0 ; j < COLS; j++){
            arr[i*COLS+j] = s[i][j];
        }
    }

    // STEP - 1 Generate all magic squares
    // STEP - 2 Find Cost and Get Min cost
    vector<int> iparr = arr;
    solve(arr, iparr, 0, taken);

    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        vector<vector<int>> s = {{4,8,2}, { 4,5,7}, {6, 1, 6}};
        // print input matrix
        // for(int i = 0 ; i < s.size(); i++){
        //     for(int j = 0 ; j < s[i].size(); j++){
        //         cout<<s[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        int val = formingMagicSquare(s);
        cout<<val<<'\n';

    }
    
    return 0;
}