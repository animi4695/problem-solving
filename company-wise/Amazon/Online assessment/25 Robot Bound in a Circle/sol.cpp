#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

bool isRobotBounded(string instructions) {
    // this map helps in identifying the direction after L/R is given as instruction
    unordered_map<char, pair<char, char>> dirs = {
        {'N', {'W', 'E'}}, {'S', {'E', 'W'}}, {'W', {'S', 'N'}}, {'E', {'N', 'S'}}
    };

    // this map helps in identifying the move when G is given as instruction
    unordered_map<char, pair<int, int>> moves = {
        {'N', {0, 1}}, {'S', {0, -1}}, {'W', {-1, 0}}, {'E', {1, 0}}
    };

    // intital pos
    int i = 0, j = 0;
    char facing = 'N';

    for(auto ch : instructions){
        if(ch == 'L'){
            facing = dirs[facing].first;
        }
        else if(ch == 'R'){
            facing = dirs[facing].second;
        }
        else if(ch == 'G'){
            i += moves[facing].first;
            j += moves[facing].second;
        }
    }

    if(i == 0 && j == 0)
        return true;

    // after few cycles, if the facing is still 'North', then it will be false.., there is a mathematical proof. 
    return facing != 'N';
}

int main(){
    cout<<isRobotBounded("GG");
}
