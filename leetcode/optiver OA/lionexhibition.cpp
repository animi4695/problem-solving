#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include<unordered_map>

using namespace std;

struct Lion {
    string name;
    int height;
    int enterTime;
    int exitTime;
};

class LionCompetition {
private:
    // vector<Lion> ourLions;
    unordered_map<string, Lion> ourLions;
    multiset<int> competitorLions;
    map<int, set<string>> ourLionsInRoom;
    map<int, Lion> ourLionDetails;

public:
    LionCompetition(vector<pair<string, int>> lions, vector<tuple<string, int, int>> schedule) {
        for (const auto& lion : lions) {
            ourLionDetails[lion.second] = {lion.first, lion.second, -1, -1};
        }
        for (const auto& sch : schedule) {
            string name = get<0>(sch);
            int enterTime = get<1>(sch);
            int exitTime = get<2>(sch);
            ourLions[name].name = name;
            // todo

            ourLions.push_back({name, lions[name].second, enterTime, exitTime});
        }
        sort(ourLions.begin(), ourLions.end(), [](const Lion& a, const Lion& b) {
            return a.enterTime < b.enterTime;
        });
    }

    void lionEntered(int currentTime, int height) {
        auto it = ourLionDetails.find(height);
        if (it != ourLionDetails.end() && it->second.enterTime == currentTime) {
            ourLionsInRoom[height].insert(it->second.name);
        } else {
            competitorLions.insert(height);
        }
    }

    void lionLeft(int currentTime, int height) {
        auto it = ourLionDetails.find(height);
        if (it != ourLionDetails.end() && it->second.exitTime == currentTime) {
            ourLionsInRoom[height].erase(it->second.name);
            if (ourLionsInRoom[height].empty()) {
                ourLionsInRoom.erase(height);
            }
        } else {
            competitorLions.erase(competitorLions.find(height));
        }
    }

    vector<string> getBiggestLions(int currentTime) {
        if (competitorLions.empty()) {
            vector<string> result;
            for (const auto& entry : ourLionsInRoom) {
                result.insert(result.end(), entry.second.begin(), entry.second.end());
            }
            sort(result.begin(), result.end());
            return result;
        } else {
            int maxCompetitorHeight = *competitorLions.rbegin();
            vector<string> result;
            for (const auto& entry : ourLionsInRoom) {
                if (entry.first >= maxCompetitorHeight) {
                    result.insert(result.end(), entry.second.begin(), entry.second.end());
                }
            }
            sort(result.begin(), result.end());
            return result;
        }
    }
};

int main() {
    vector<pair<string, int>> lions = {{"marry", 300}, {"rob", 250}};
    vector<tuple<string, int, int>> schedule = {{"marry", 10, 15}, {"rob", 13, 20}};
    LionCompetition competition(lions, schedule);

    competition.lionEntered(8, 200);
    competition.lionEntered(10, 310);
    competition.lionEntered(10, 300);

    cout << competition.getBiggestLions(11).size() << endl;

    competition.lionEntered(13, 250);
    competition.lionLeft(13, 310);

    vector<string> result = competition.getBiggestLions(13);
    cout << result.size() << " ";
    for (const string& name : result) {
        cout << name << " ";
    }
    cout << endl;

    competition.lionLeft(15, 300);

    result = competition.getBiggestLions(16);
    cout << result.size() << " ";
    for (const string& name : result) {
        cout << name << " ";
    }
    cout << endl;

    competition.lionLeft(16, 200);
    competition.lionLeft(20, 250);

    return 0;
}
