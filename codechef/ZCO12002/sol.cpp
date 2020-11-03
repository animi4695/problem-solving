#include <iostream>
#define ll long long
#include <vector>
#include<algorithm>

using namespace std;

ll min(ll a,ll b){
    return (a<b)?a:b;
}

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> nVec;
    vector<ll> xArr;
    vector<ll> yArr;
    for (ll i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nVec.push_back(make_pair(a, b));
    }

    for (ll i = 0; i < x; i++)
    {
        int a;
        cin >>a;
        xArr.push_back(a);
    }

    for (ll i = 0; i < y; i++)
    {
        int a;
        cin >>a;
        yArr.push_back(a);
    }

    sort(xArr.begin(), xArr.end());
    sort(yArr.begin(), yArr.end());

    ll ans = 99999999;

    for (ll i = 0; i < nVec.size(); i++)
    {
        //find best v wormhole for entering the contest
        // NAIVE SOLUTION 
        // int lowerBound = 0;
        // // problem with below code is We are trying to find lowerbound by traversing complete xArr
        // for(ll j = xArr.size()-1; j >= 0; j--){
        //     if(xArr[j] <= nVec[i].first)
        //     {
        //         lowerBound = xArr[j];
        //         break;
        //     }
        // }

        // //find best W wormhole for exiting the contest
        // int upperBound = 0;
        // for(ll j = 0; j < yArr.size(); j++){
        //     if(yArr[j] >= nVec[i].second) 
        //     {
        //         upperBound = yArr[j];
        //         break;
        //     }
        // }
        // if(upperBound > 0 && lowerBound > 0){
        //     // cout<<upperBound <<" - " << lowerBound<< endl;
        //     ans.push_back(upperBound - lowerBound + 1);
        // }


        ll start = xArr[0];
	    ll left = 0;
	    ll right = x-1;
	    while(left <= right){
	        int mid = (left + right)/2;
	        if(xArr[mid] <= nVec[i].first){
	            start = xArr[mid];
	            left = mid+1;
	        }else{
	            right = mid-1;
	        }
	    }

        ll end = yArr[y-1];
	    left = 0;
	    right = y-1;
	    while(left<=right){
	        int mid = (left + right)/2;
	        if(yArr[mid] >= nVec[i].second){
	            end = yArr[mid];
	            right = mid-1;
	        }else{
	            left = mid+1;
	        }
	    }

        if(start <= nVec[i].first && end >= nVec[i].second){
	        ans = min(end - start + 1,ans);
	    }
    }
    cout<<ans<<endl;
    return 0;
}