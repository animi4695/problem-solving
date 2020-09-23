#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(int arr[], int n){
    // optimized solution
    // Idea - optimally find the 1st smaller element
    // TC - O(N)
    // SC - O(N)

    if(n == 1) return arr[0];

    stack<int> st;
    long long maxArea = 0;
    for(int i = 0; i < n; i++){
        if(st.empty() || arr[st.top()] <= arr[i]){
            st.push(i++);
        }
        else{
            int currMax = st.top();
            st.pop();
            int area = arr[currMax]*(st.empty() ? i : (i-1-st.top());

            if(area > maxArea) maxArea = area;
        }
    }

    // process the left out indexes in stack
    while (!st.empty())
    {
        int currMax = st.top();
        st.pop();
        int area = arr[currMax]*(st.empty() ? i : (i-1-st.top()));
        if(area > maxArea) maxArea = area;
    }
    return maxArea;
}

long long solve(int arr[], int n){
    // bruteforce 
    // TC - O(N^2)
    // SC - O(1)

    if(n == 1){
        return arr[0];
    }
    int p1 = 0, p2 = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        p1 = -1;
        p2 = -1;
        for(int j = i; j >=0; j--){
            if(arr[j] < arr[i]){
                p1 = j;
                break;
            }
        }
        for(int j = i; j < n; j++){
            if(arr[j] < arr[i]) {
                p2 = j;
                break;
            }
        }
        if(p2 == -1) p2 = n;
        if((p2-p1-1)*arr[i] > ans) ans = (p2-p1-1)*arr[i];
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
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];

        cout<<solve1(arr, n)<<"\n";
    }
    
    return 0;
}