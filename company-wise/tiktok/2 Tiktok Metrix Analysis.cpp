/*

ByteDance, renowned for its innovative products like TikTok, is expanding its
financial analytics capabilities to offer more comprehensive insights for its creators 
and partners. 
The task is to optimize a data processing pipeline for TikTok's financial module platform.
The objective is to enhance the analytics to efficiently identify the longest 'good subarray' 
of financial metrics meeting a specific criterion.

Given an array financialMetrics of size n where each element represents a numerical financial
metric, and a threshold value limit, the goal is to find the maximum length of a non-empty 
consecutive sequence of data points in financialMetrics that satisfies the following condition:

Each data point in the sequence must be greater than limit / the length of the sequence. 
If there is no termed 'good' subarray of any length, this sequence is termed a subarray in the dataset, 
the function should return -1.

Function Signature: int findGoodSubarray(int[] financialMetrics, int limit)

Example 1:

Input:  financialMetrics = [1, 3, 4, 3, 1], limit = 6
Output: 3 
Explanation:

Let's explore all subarrays of financialMetrics

Analysis of all Subarrays
Subarray	        Comparison	Evaluation
[1]	                1 < (6/1=6)	Not a good subarray
[3]	                3 < (6/1=6)	Not a good subarray
[4]	                4 < (6/1=6)	Not a good subarray
[3]	                3 < (6/1=6)	Not a good subarray
[1]	                1 < (6/1=6)	Not a good subarray
[1, 3]	            1 < (6/2=3)	Not a good subarray
[3, 4]	            3 < (6/2=3)	Not a good subarray
[4, 3]	            4 < (6/2=3)	Not a good subarray
[3, 1]	            3 < (6/2=3)	Not a good subarray
[1, 3, 4]	        1 < (6/3=2)	Not a good subarray
[3, 4, 3]	        3,4 > (6/3=2)	good subarray
[4, 3, 1]	        4 < (6/3=2)	Not a good subarray
[1, 3, 4, 3]	    1 < (6/4=1.5)	Not a good subarray
[3, 4, 3, 1]	    1 < (6/4=1.5)	Not a good subarray
[1, 3, 4, 3, 1]	    1 < (6/5=1.2)	Not a good subarray

Thus, the maximum length of a good subarray is 3 and the good subarray is [3,4,3].


Function Description
Complete the function getMaxGoodSubarrayLength in the editor. getMaxGoodSubarrayLength has the following parameter:

int limit
int financialMetrics[n]: an array of length n
Returns
int: the maximum length of a good subarray of financialMetrics.
Constraints
1 ≤ n ≤ 10^5
1 ≤ financialMetrics[i] ≤ 10^9
1 ≤ limit ≤ 10^9
Input Format For Custom Testing
Sample Input For Custom Testing
6
6
1 3 4 3 1


Hint - In this problem, you need to find the longest consecutive subarray that meets 
the condition. The key is to understand the definition of a "good subarray"— 
where each element in the subarray must be greater than the limit divided by the length
of the subarray. You can iterate through the array, check if each subarray meets the 
criteria, and keep track of the maximum length that satisfies the condition.



*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int getMaxGoodSubarrayLength(vector<int>& financialMetrics, int limit) {
    int res = 0;

    // min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i < financialMetrics.size(); i++){
        pq.push({financialMetrics[i], i});
    }

    // sliding window
    int l = 0, r = financialMetrics.size() - 1;
    while(l <= r && !pq.empty() && pq.top().first <= limit / (r - l + 1)){
        int idx = pq.top().second;
        int val = pq.top().first;
        pq.pop();

        if(idx < l || idx > r){
            continue;
        }
        
        if(idx - l < r - idx) {
            l = idx + 1;
        }
        else{
            r = idx - 1;
        }
    }

    return (r-l+1) > 0 ? (r-l+1) : -1;
}

int main (){
    int limit = 6;
    vector<int> financialMetrics = {1,3,4,3,1};
    cout<<getMaxGoodSubarrayLength(financialMetrics, limit)<<"\n";

    return 0;
}