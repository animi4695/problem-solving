#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        multiset<int> ms;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        ms.insert(arr[0]);
        
        for (int i = 1; i < n; i++)
        {
            auto a = ms.upper_bound(arr[i]);
            if( a == ms.end()){
                // cout<<"end " <<arr[i]<<" ";
                ms.insert(arr[i]);
            }
            else{
                // cout<<*a<< " ";
                ms.erase(a);
                ms.insert(arr[i]);
            }
        }
        cout<<ms.size()<<" ";
        for(auto it = ms.begin(); it!=ms.end(); it++)  {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}