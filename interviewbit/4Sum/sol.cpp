#include<iostream>
#include<limits>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// using map but not an optimal solution
vector<vector<int>> fourSum1(vector<int>& A, int B){
    unordered_map<int, vector<pair<int,int>>> mymap;
    vector<vector<int>> res;
    int n = A.size();

    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            int sum = A[i] + A[j];

            if(mymap.find(B-sum) != mymap.end()){
                vector<pair<int,int>> myV = mymap[B-sum];

                for(int k = 0; k < myV.size(); ++k){
                    if(myV[k].first != i && myV[k].first != j && myV[k].second != i && myV[k].second != j){
                        vector<int> temp;
                        temp.push_back(A[myV[k].first]);
                        temp.push_back(A[myV[k].second]);
                        temp.push_back(A[i]);
                        temp.push_back(A[j]);
                        sort(temp.begin(), temp.end());

                        // check if the temp is already pushed to avoid duplicates
                        if(find(res.begin(), res.end(), temp) == res.end()) res.push_back(temp);
                    }
                }
            }
            mymap[sum].push_back({i,j});
        }
    }
    sort(res.begin(), res.end());
    for(auto c : res){
        for(auto a : c){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return res;
}

vector<vector<int>> fourSum(vector<int>& A, int B){
    sort(A.begin(), A.end());
    int n = A.size();

    vector<vector<int>> res;

    // i contains the 1st ele.. total we need 4 for we go till n-3
    for(int i = 0 ; i < n-3; ++i){
        if(i > 0 && A[i] == A[i-1]) continue;
        // j contains the 2nd ele
        for(int j = i+1; j < n-2; ++j){
            if(j > i+1 && A[j] == A[j-1]) continue;

            int p1 = j+1, p2 = n-1;
            while(p1 < p2){
                int sum = A[i] + A[j] + A[p1] + A[p2];
                if(sum == B){
                    vector<int> temp;
                    temp.emplace_back(A[i]);
                    temp.emplace_back(A[j]);
                    temp.emplace_back(A[p1]);
                    temp.emplace_back(A[p2]);
                    res.emplace_back(temp);
                    ++p1;
                    
                    // skip duplicates
                    while(p1 < p2 && A[p1] == A[p1-1])
                        ++p1;
                }
                else if(sum < B)
                    ++p1;
                else
                    --p2;
            }
        }
    }
    for(auto c : res){
        for(auto a : c){
            cout<<a<<" ";
        }
        cout<<"\n";
    }

    return res;
}

int main(){
    vector<int> A = {1, 0, -1, 0, -2, 2};
    int B = 0;
    fourSum1(A, B);
    return 0;
}