#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int solve1(int A[], int B[], int C[], int D[], int n){
    // Slightly optimized - Meet in the Middle Technique
    // Idea -> A^B^C^D = 0, so A^B = 0^C^D
    // TC - O(N^2)
    // SC - O(N)
    int ans = 0;
    unordered_map<int, int> ump;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = A[i]^B[j];
            ump[temp]++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = C[i]^D[j];
            auto itr = ump.find(temp);
            if(itr != ump.end()){
                ans += itr->second;
            }
        }
    }

    return ans;
}

int solve(int A[], int B[], int C[], int D[], int n){
    // Brute Force
    // TC - O(N^4)
    // SC - O(1)
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++ ){
                    if((A[i]^B[j]^C[k]^D[l]) == 0){
                        cout<<A[i]<<" "<<B[j]<<" "<<C[k]<<" "<<D[l]<<"\n";
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int A[n], B[n], C[n], D[n];
        for(int i = 0; i < n; i++) cin>>A[i];
        for(int i = 0; i < n; i++) cin>>B[i];
        for(int i = 0; i < n; i++) cin>>C[i];
        for(int i = 0; i < n; i++) cin>>D[i];

        cout<<solve1(A, B, C, D, n)<<"\n";
    }
    
    return 0;
}