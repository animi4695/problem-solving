#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
void solve(vector<vector<char>>& arr, int countX, int countO, int countE) {
    // check if player 'X' won
    // for a player to win. there are 8 possible ways (3 rows, 3 columns, 2 diagonals)
    int XWon = 0, OWon = 0;
    
    // check 3 rows, 3 columns for X and O
    for(int i = 0; i < 3; i++){
        if(arr[i][0] == 'X' && arr[i][1] == 'X' && arr[i][2] == 'X')
            XWon = 1;
        if(arr[0][i] == 'X' && arr[1][i] == 'X' && arr[2][i] == 'X')
            XWon = 1;

        if(arr[i][0] == 'O' && arr[i][1] == 'O' && arr[i][2] == 'O')
            OWon = 1;
        if(arr[0][i] == 'O' && arr[1][i] == 'O' && arr[2][i] == 'O')
            OWon = 1;
    }

    // diagonal for X
    if(arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
        XWon = 1;
    if(arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
        XWon = 1;
    
    // diagonals for O
    if(arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
        OWon = 1;
    if(arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
        OWon = 1;

    // Check and print the ans.
    // print 3 
    //      when the board is in wrong way(i.e both are winners) or the difference between Xs and Os is never greater than 1.
    //      because X always start the game
    if((XWon == 1 && OWon == 1) || countX-countO < 0 || countX-countO > 1)
        cout<<"3";
    // print 2:
    //      when board is empty or neither of X and O is won and still few empty slots are left
    else if((countO == 0 && countX == 0 && countE == 9) || (XWon == 0 && OWon == 0 && countE > 0)){
        cout<<"2";
    }
    // print 1:
    //      when X won and count of X > count O
    //      when O won and count of O == count of X
    //      when neither of them won and no empty slots are left (draw case)
    else if((XWon == 1 && OWon == 0 && countX > countO) || (OWon == 1 && XWon == 0 && countO == countX) || (XWon == 0 && OWon == 0 && countE == 0))
        cout<<"1";
    else
        cout<<"3";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        vector<vector<char>> arr(3, vector<char>(3));
        int countX = 0, countO = 0, countE = 0; // countE means countEmty
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin>>arr[i][j];
                if(arr[i][j] == 'X')
                    countX++;
                else if(arr[i][j] == 'O')
                    countO++;
                else
                    countE++;
            }
        }

        solve(arr, countX, countO, countE);
        cout<<"\n";
    }
    return 0;
}