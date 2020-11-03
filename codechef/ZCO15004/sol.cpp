#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>

using namespace std;

// This is O(NK) solution which can be optimized by finding the left and right smallest values
// in O(N) using stacks. Then the solution's time complexity will be around O(NLogN)
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> coords;

    // Dummy points for edge cases
    coords.push_back(make_pair(0, 500));
    coords.push_back(make_pair(100000, 500));

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        coords.push_back(make_pair(a, b));
    }

    sort(coords.begin(), coords.end());

    int result = 0;
    for(int i = 1; i< coords.size()-1; i++){
        int maxdiff = 0;
        maxdiff =  max(coords[i].first - coords[i-1].first, coords[i+1].first - coords[i].first);
        int adjArea = 500 * maxdiff;
        result = max(adjArea, result);
    }

    // find left(x) and right(y) caps for each top point(y)
    for (int i = 0; i < coords.size(); i++)
    {
        int left = 0;
        int right = 100000;
        for (int j = i; j< coords.size(); j++){
            if(coords[j].second < coords[i].second){
                right = coords[j].first;
                break;
            }
        }

        for(int j = i; j > 0; j--){
            if(coords[j].second < coords[i].second){
                left = coords[j].first;
                break;
            }
        }

        int area = (right - left)*coords[i].second;
        // cout<<"left - "<< left << " right - " << right << " area - " << area<<" ccords - "<< coords[i].first << "-" << coords[i].second<<endl;
        result = max(area, result);
    }

    cout<<result<<endl;
    return 0;
}