#include<iostream>
#include <limits>
#include<vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<char>> arr(n, vector<char>(n, '.'));
        int i, j, k, l;
        bool yo = false;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                cin>>arr[r][c];
                if(arr[r][c] == '*' && !yo) {
                    i = r;
                    j = c;
                    yo = true;
                }
                else if(arr[r][c] == '*' && yo){
                    k = r;
                    l = c;
                }
            }
        }
        // check for same row, same col, diagonal
        if(i == k){
            // same row
            if(i == n-1){
                // bottom
                arr[i-1][j] = '*';
                arr[i-1][l] = '*';
            }
            else{
                // top + others
                arr[i+1][j] = '*';
                arr[i+1][l] = '*';
            }
        }
        else if(j == l){
            // same col
            if(j == n-1){
                // right most
                arr[i][j-1] = '*';
                arr[k][j-1] = '*';
            }
            else{
                // left most + others
                arr[i][j+1] = '*';
                arr[k][j+1] = '*';
            }
        }
        else{
            // diag
            arr[i][l] = '*';
            arr[k][j] = '*';
            arr[i][j] = '*';
            arr[k][l] = '*';
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                cout<<arr[r][c];
            }
            cout<<"\n";
        }

    }
    
    return 0;
}