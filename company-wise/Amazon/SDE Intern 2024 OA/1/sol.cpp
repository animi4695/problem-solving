#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

vector<int> getMaxCopies(const vector<int>& portalUpdate);

int main() {
    vector<int> portalUpdate = {6, 6, 2, -6, -2, -6};
    vector<int> result = getMaxCopies(portalUpdate);

    cout << "Maximum copies after each update: ";
    for (int copies : result) {
        cout << copies << " ";
    }

    return 0;
}

vector<int> getMaxCopies(const vector<int>& portalUpdate) {
    unordered_map<int, int> inventory;
    vector<int> result;

    int maxCopies = 0;

    for (int update : portalUpdate) {
        if (update > 0) {
            inventory[update]++;
        } else {
            inventory[-update]--;

            if (inventory[-update] == 0) {
                inventory.erase(-update);
            }

            maxCopies = 0;
            for (const auto& entry : inventory) {
                maxCopies = max(maxCopies, entry.second);
            }
        }
        result.push_back(maxCopies);
    }
    return result;
}

