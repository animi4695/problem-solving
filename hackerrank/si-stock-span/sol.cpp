#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

// Approach - 2
void solve1(int arr[], int n){
    // Idea - use stack to store indices. for every element,
    // pop the stack until you find a value greater than the current element and find the distance

    stack<int> st;
    st.push(0);
    cout<<1<<" ";
    for(int i = 1; i < n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        st.empty() ? cout<<i+1 : cout<<(i-st.top());
        cout<<" ";
        st.push(i);
    }
    cout<<"\n";
}

// Approach - 1
void solve(int arr[], int n){
    // bruteforce
    int ptr = 0;
    for (size_t i = 0; i < n; i++)
    {
        int count = 0;
        ptr = i;
        while(ptr >= 0 && arr[ptr] <= arr[i]){
            count++;
            ptr--;
        }
        cout<<count<<" ";
    }
    cout<<"\n";
    
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

        solve1(arr, n);
    }
    
    return 0;
}