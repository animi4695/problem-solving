#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<climits>
#include<unordered_map>

using namespace std;

vector<int> GetLeft(vector<int>& nums)
  {
    unordered_map<int, vector<int>> umap; 
    for(int i=0; i<nums.size(); i++)
    {
        umap[nums[i]].push_back(i);
    }

    while(true)
    {
        int choosePriority = INT_MAX;
        for(auto& [priority, idList] : umap)
        {
            int maxPriority = INT_MIN;
            if(idList.size() >= 2)
            {
                maxPriority = max(maxPriority, priority);
            }
            choosePriority = maxPriority;
        }

        if(choosePriority == INT_MIN)
        {
            int minPriority = INT_MAX;
            for(auto& [priority, idList] : umap)
            {
                if(idList.size() >= 2)
                {
                    minPriority = min(minPriority, priority);
                }
            }
            choosePriority = minPriority;
        }

        if(choosePriority == INT_MAX || choosePriority == INT_MIN)
        {
            break;
        }

        auto& idList = umap[choosePriority];
        int id1 = idList[0], id2 = idList[1];
        idList.erase(idList.begin());
        idList.erase(idList.begin());
        if(idList.size()==0) umap.erase(choosePriority);
        umap[choosePriority/2].push_back(id2);
    }

    vector<int> ans;
    for(auto[x, _] : umap)
    {
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end(), [&umap](int a, int b)
    {
        return umap[a][0] < umap[b][0];
    }
    );
    return ans;
  }
int main() {
    vector<int> priority = {6,6,6,1,1,2};

    vector<int> res = GetLeft(priority);

    for (int p : res) {
        cout << p << " ";
    }

    return 0;
}
