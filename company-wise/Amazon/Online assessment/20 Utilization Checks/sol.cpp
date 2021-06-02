// https://www.youtube.com/watch?v=eZZehso7cTE

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int finalInstances(int instances, vector<int> avgUtil){
    for(int i = 0; i < avgUtil.size(); i++) {
        if(avgUtil[i] < 25 && instances > 1){
            instances = (int)ceil(instances/2);
            i += 10;
        }

        if(i < avgUtil.size() && avgUtil[i] > 60 && instances < 20000000){
            instances *= 2;
            i += 10;
        }
    }
    return instances;
}

int main(){
    vector<int> avgUtil = {25, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 80};
    cout<<finalInstances(2, avgUtil);
}
