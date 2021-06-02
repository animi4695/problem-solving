#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
vector<string> findNearest(vector<string>& points, vector<int>& xCo, vector<int>& yCo, vector<string>& queries, int n);
int calcDist(string& q, string& str, map<string, int>& pointsToIdx, vector<int>& xCo, vector<int>& yCo){
    int qIdx = pointsToIdx[q];
    int strIdx = pointsToIdx[str];
    return (int)fabs(int(xCo[qIdx] - xCo[strIdx])) + (int)fabs(int(yCo[qIdx] - yCo[strIdx]));
}

int main(){
    vector<string> points = {"p1", "p2","p3"};
    vector<int> xCoo = {30, 20, 10};
    vector<int> yCoo = {30, 20, 30};
	vector<string>  queries = {"p3","p2","p1"};
    int n = 3;
    vector<string> res = findNearest(points, xCoo, yCoo, queries, n);
    for(auto r : res){
        cout<<r<<" ";
    }

}

vector<string> findNearest(vector<string>& points, vector<int>& xCo, vector<int>& yCo, vector<string>& queries, int n){
    vector<string> res(queries.size(), "NULL");

    map<int, vector<string>> xToPoint, yToPoint; // maps from x, y co-ord to points
    map<string, int> pointsToIdx; // maps from point name to its idx

    for(int i = 0; i < n; i++){
        xToPoint[xCo[i]].push_back(points[i]);
        yToPoint[yCo[i]].push_back(points[i]);
        pointsToIdx[points[i]] = i;
    }

    for(int i = 0; i < queries.size(); i++){
        string q = queries[i];
        int qIdx = pointsToIdx[q];
        vector<string> xNbrs, yNbrs;
        xNbrs = xToPoint[xCo[qIdx]];
        yNbrs = yToPoint[yCo[qIdx]];
        // if there are no neighbours, skip
        if(xNbrs.size() == 1 && yNbrs.size() == 1)
            continue;
        int minDist = INT32_MAX;
        string min = "NULL";
        for(auto str : xNbrs){
            if(str == q)
                continue;
            int dist = calcDist(q, str, pointsToIdx, xCo, yCo);
            if(dist < minDist){
                minDist = dist;
                min = str;
            }
        }

        for(auto str : yNbrs){
            if(str == q)
                continue;
            int dist = calcDist(q, str, pointsToIdx, xCo, yCo);
            if(dist < minDist){
                minDist = dist;
                min = str;
            }
        }
        res[i] = min;
    }


    return res;
}