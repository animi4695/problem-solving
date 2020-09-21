#include<iostream>
#include <limits>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;
bool sumOfPairs(vector<int>& arr, int n, int k);
void merge(vector<int>& arr, int lo, int hi);
void mergeSort(vector<int>& arr, int lo, int hi);

void merge(vector<int>& arr, int lo, int hi){

    int mid = (lo + hi)/2;
    vector<int> temp(hi-lo+1);

    // 2 pointer approach to merge the two parts of arrays
    int p1 = lo, p2 = mid+1, k = 0;

    while (p1 <= mid && p2 <= hi)
    {
        if(arr[p1] > arr[p2])
            temp[k++] = arr[p2++];
        else
            temp[k++] = arr[p1++];
    }

    while(p1 <= mid)
        temp[k++] = arr[p1++];
    while(p2 <= hi)
        temp[k++] = arr[p2++];
    
    // copy the temp arr to original array
    for (int i = 0; i < k; i++)
        arr[lo+i] = temp[i];
}

void mergeSort(vector<int>& arr, int lo, int hi){
    if(lo == hi) return;
    int m = (lo + hi)/2;
    mergeSort(arr, lo, m);
    mergeSort(arr, m+1, hi);
    merge(arr, lo, hi);
}

bool sumOfPairs(vector<int>& arr, int n, int k){
    // Approach
    //      STEP 1 - Sort the array
    //      STEP 2 - Use two pointer technique to find pairs summing to K
    mergeSort(arr, 0, n-1);
    // for(auto c : arr){
    //     cout<<c<<" ";
    // }

    int p1 = 0, p2 = n-1;
    while (p1 < p2)
    {
        if(arr[p1] + arr[p2] == k){
            return true;
        }
        else if(arr[p1] + arr[p2] < k){
            p1++;
        }
        else{
            p2--;
        }
    }
    return false;
}

bool BSR(vector<int>& arr, int k, int lo, int hi){

    if(lo > hi) return false;
    
    int mid = (lo + hi)/2;
    if(arr[mid] == k)   return true;
    if(arr[mid] > k) return BSR(arr, k, lo, mid-1);
    return BSR(arr, k, mid+1, hi);
}

bool sumOfPairsBS(vector<int>& arr, int n, int k){
    sort(arr.begin(), arr.end());

    // implement BSI/BSR
    for (int i = 0; i < n; i++)
    {
        // a + b = k
        // b = k - a;
        int a = arr[i];
        int b = k-a;

        if(BSR(arr, b, 0, n-1))
            return true;
    }
    return false;
}

// using unordered_map
bool sumOfPairHM(vector<int> &arr, int n, int k){
    unordered_map<int, int> ump;
    for(auto a : arr){
            ump[a]++;
    }
    for(int i = 0 ; i < n; i++){
        int a = arr[i];
        int b = k - a;
        auto itr = ump.find(b);
        if(itr != ump.end()){
            if(a != itr->first)
                return true;
            
            if((a = itr->first) && (itr->second > 1))
                return true;
        }
    }
    return false;
}

// using unordered_set
bool sumOfPairHS(vector<int>& arr, int n, int k){
    unordered_set<int> uset;
    
    for(int i = 0 ; i < n; i++){
        int a = arr[i];
        int b = k - a;
        auto itr = uset.find(b);
        if(itr != uset.end()){
            return true;
        }
        uset.insert(a);
    }
    
    return false;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin>>arr[i];

        if(sumOfPairHM(arr, n, k)){
            cout<<"True\n";
        }
        else{
            cout<<"False\n";
        }
        
    }
    
    return 0;
}