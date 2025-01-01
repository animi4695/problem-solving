
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
long long bsearch(long long x, long long n) {
    long long l = 1, r = n, k = 1;
    while(l <= r){
        long long mid = (l + r)/2;
        if(n / mid == x){
            k = mid;
            l = mid + 1;
        }
        else if(n / mid < x){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return k;
}


long long getDataDependenceSum(long long n) {
    // eg. for n = 5, x = 5, k = 1 => floor(5 (n)/1 (k)) = 5 (x)
    long long ans = n; // starting with n as x starts as n when k = 1;
    long long x = 5, k = 1;

    while(k <= n) {
        // find largest k where floor(n/k) = x;
        k = bsearch(x, n) + 1;
        x = n/k; //update x for next range
        ans += x;
    }
    return ans;
}

int main() {
    int n = 13;
    cout<<getDataDependenceSum(n);
}



// Data analysts at Amazon are analyzing time-series data. It was concluded that the data of the nth item was dependent on the data of some xth day if there is a positive integer k such that floor(n / k) = x where floor() represents the largest integer less than or equal to z.

// Given n, find the sum of all the days' numbers on which the data of the xth (0 ≤ x < n) will be dependent.

// Function Description

// Complete the function getDataDependenceSum in the editor below.

// getDataDependenceSum takes the following arguments:

// long int n: the day to analyze the data dependency for
// Returns

// long int: the sum of days on which the data is dependent

// Input Format For Custom Testing

// The first line contains a long integer, n.