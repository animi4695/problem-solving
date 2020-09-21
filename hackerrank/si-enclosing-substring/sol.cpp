#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;
bool isValid(string b, int mid, int cntA[]);

int solve(string a, string b){
    // Brute Force
    // TC - O(M + N^2(N+26))
    // SC - O(1)
    int cntA[26] = {0};
    for(int i = 0; i < a.length(); i++) cntA[a[i]-'a']++;

    int res = INT_MAX;
    for(int i = 0 ; i < b.length(); i++){
        string temp = "";
        int cntB[26] = {0};
        for (int j = i; j < b.length(); j++){
            bool isEnclosedString = true;
            temp += b[j];
            cntB[b[j] - 'a']++;
            for (int k = 0; k < 26; k++){
                if (cntB[k] < cntA[k])
                {
                    isEnclosedString = false;
                    break;
                }
            }
            if (isEnclosedString){
                res = min(res, (int)temp.length());
            }
        }
    }

    return (res == INT_MAX)? -1 : res;
}

int solve1(string a, string b){
    // Optimized
    // Idea - Using binary search, assume something as an answer and try to check if substrings of that assumed 
    //        length is valid or not. If they are valid, search for better.
    // TC - O(M + N*Log(M-N+1))
    // Sc - O(1)
    int ans = -1;
    int cntA[26] = {0};

    for(int i= 0; i< a.length(); i++) cntA[a[i]-'a']++;

    int lo = a.length(), hi = b.length();
    while (lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(isValid(b, mid, cntA)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return ans;
}

bool isValid(string b, int mid, int cntA[]){
    int initial = 0, i =0, cntB[26] = {0};
    // First check if 0-mid is valid
    for(i = 0; i < mid; i++){
        cntB[b[i]-'a']++;
    }
    bool isEnclosedString = true;
    for(int j = 0; j < 26; j++){
        if(cntB[j] < cntA[j]){
            isEnclosedString = false;
            break;
        }
    }

    if(isEnclosedString) return true;

    // now check from mid-end by incrementing one right and decrementing one left.
    while(i < b.length()){
        isEnclosedString = true;
        cntB[b[i++] - 'a']++;
        cntB[b[initial++]-'a']--;
        for(int j = 0; j < 26; j++){
            if(cntB[j] < cntA[j]){
                isEnclosedString = false;
                break;
            }
        }
        if(isEnclosedString) return true;
    }

    return false;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        cout<<solve1(a,b)<<"\n";
    }
    
    return 0;
}