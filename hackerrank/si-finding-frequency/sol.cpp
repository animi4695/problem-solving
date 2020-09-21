#include<iostream>
#include <limits>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int BS1(int arr[], int n, int x){
    // find first occurrance of x
    int lo =0, hi = n-1, result = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi)/2;
        if(arr[mid] == x){
            result = mid;
            hi = mid-1;
        }
        else if(arr[mid] < x)
            lo = mid+1;
        else
            hi = mid-1;
    }
    return result;
}

int BS2(int arr[], int n, int x){
    // find last occurrance of x
    int lo = 0, hi = n-1, result = -1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(arr[mid] == x){
            result = mid;
            lo = mid+1;
        }
        else if(arr[mid] < x)   lo = mid+1;
        else hi = mid-1;
    }
    return result;
}

void solve5(unordered_map<int,int>& mp, int x){
    auto itr = mp.find(x);
    if(itr != mp.end())
       cout<<itr->second<<"\n";
    else 
       cout<<"0\n";
}

void solve4(int arr[], int n, int x){
    // sort + 2 ptr
    sort(arr, arr+n);

    int p1 = 0, p2 = n-1;
    while (p1 < n)
    {
        if(arr[p1] == x) break;
        p1++;
    }

    while (p2 >= 0)
    {
        if(arr[p2] == x) break;
        p2--;
    }
    
    // while (p1 <= p2)
    // {
    //     if(arr[p1] != x) p1++;

    //     if(arr[p2] != x) p2--;
    // }
    if(p2 < 0 && p1 >= n) cout<<"0\n";
    else cout<<p2-p1+1<<"\n";
    
}

void solve3(int arr[], int n, int x){
    // sort + 2 Binary search to find first and last occurance
    sort(arr, arr+n);

    // 2 Binary Search
    int idx1 = BS1(arr, n, x);
    int idx2 = BS2(arr, n, x);
    if(idx1 == -1 && idx2 == -1)
        cout<<0<<"\n";
    else
        cout<<idx2-idx1+1<<"\n";
}

void solve2(int arr[], int n, int x){
    // sort + 1 BS + expand left and right to count.
    sort(arr, arr+n);

    // Binary Search
    int lo = 0, hi = n-1;
    int idx = -1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(arr[mid] == x){
            idx = mid;
            break;
        }
        else if(arr[mid] < x)
            lo = mid+1;
        else
            hi = mid-1;
    }
    int rightIdx = idx;
    if(idx != -1){
        while(idx >= 0&& arr[idx-1] == x){
            idx--;
        }
        while(rightIdx <n && arr[rightIdx+1] == x){
            rightIdx++;
        }
        cout<<rightIdx-idx+1<<"\n";
    }
    else
    {
        cout<<"0\n";
    }
    
}

void solve1(int arr[], int n, int x){
    // Bruteforce
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == x) count++;
    }
    cout<<count<<"\n";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++) cin>>arr[i];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int q;
    cin>>q;
    while (q--)
    {
        int x;
        cin>>x;
        // solve4(arr, n, x);
        solve5(mp, x);
    }
    
    return 0;
}