#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

int findUniqueValues(vector<int> experience);
int main(){
    vector<int> experience = {1,4,1,3,5,6};
    // Expected output = 2
    int res = findUniqueValues(experience);
    cout<<res;
    return 0;
}

int findUniqueValues(vector<int> experience) {
    unordered_set<double> uniqueValues;
    sort(experience.begin(), experience.end());
    int i = 0, j = experience.size() - 1;

    while(i < j) {
        double combinedExp = (experience[i] + experience[j])/ 2.0;
        uniqueValues.insert(combinedExp);
        i++;
        j--;
    }

    return uniqueValues.size();
}

