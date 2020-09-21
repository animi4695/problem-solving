#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>


using namespace std;
vector<vector<int>> threeSum(vector<int> A){
    int n = A.size();
    sort(A.begin(), A.end());
    vector<vector<int>> result;
    for(int i = 0 ; i < n-2; i++){
        // to avoid duplicates
        if(i > 0 && A[i] == A[i-1]) continue;
        // apply 2 ptr technique to find the other two
        int p1 = i+1, p2 = n-1;

        while(p1 < p2){
            long long sum = (long long)A[i] + (long long)A[p1] + (long long)A[p2];
            if(sum == 0){
                vector<int> temp = {A[i] , A[p1], A[p2]};
                int s = result.size();
                if(s > 0 && result[s-1][0] ==temp[0] &&  result[s-1][1] == temp[1] && result[s-1][2] == temp[2]);
                else{
                    result.push_back(temp);
                }
                p1++;
                p2--;
            }
            else if(sum > 0){
                p2--;
            }
            else {
                p1++;
            }
        }
    }
    for(auto res : result){
        for(auto r : res){
            cout<<r<<" ";
        }
        cout<<"\n";
    }
    return result;
}

int main(){
    vector<int> A = {2147483647, -2147483648, -2147483648, 0, 1};
    threeSum(A);
    return 0;
}