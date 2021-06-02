#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int roverMove(vector<string> cmds, int n){
    int row = 0, col = 0;
    for(auto cmd : cmds) {
        if(cmd == "RIGHT"){
            if(col < n-1)
                col = col+1;
        }
        else if(cmd == "LEFT"){
            if(col > 0)
                col = col-1;
        }
        else if(cmd == "UP"){
            if(row > 0)
                row = row-1;
        }
        else{
            if(row < n-1)
                row = row+1;
        }
    }
    return (row*n) + col;
}


int main() {
    vector<string> cmds = {"RIGHT", "DOWN", "LEFT", "LEFT", "DOWN"};
    cout<<roverMove(cmds, 4);

}