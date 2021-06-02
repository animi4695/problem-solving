#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

/*
from leetcode comments:
Time Complexity: O(N)
Space Complexity: O(N)

         <-------------------------------------------RightBound[4]=2              (Denotes count of  * that are left to the most recent | )
          |          *           *           |            *         |          * 
Indexes:  0          1           2           3            4         5          6          
   LeftBound[0]=4 ------------------------------------------------------>      (Denotes the count of * that are right to the most recent | )

Total = 4
Ans = rigthBound + leftBound - total           (Adding both leftBound and rightBound some values get counted twice, and this duplicate values represent our answer. Total is subtracted to remove the values only counted ones)

*/

vector<int> numberOfItems(string s, vector<int> startInd, vector<int> endInd){
    int n = s.size();
    vector<int> leftBound(n,0), rightBound(n, 0);

    int count = 0, total = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '|'){
            count = total;
        }
        else if(s[i] == '*'){
            total++;
        }
        rightBound[i] = count;
    }

    count = 0;
    total = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '|'){
            count = total;
        }
        else if(s[i] == '*'){
            total++;
        }
        leftBound[i] = count;
    }

    vector<int> ans;
    for(int i = 0; i < startInd.size(); i++){
        // -1 because of 0-based indexing in given string.
        int start = startInd[i]-1;
        int end = endInd[i]-1;
        count = leftBound[i] + rightBound[i]-total;

        if(start>=0 && end<n && start<end && count>0){
            ans.push_back(count);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}