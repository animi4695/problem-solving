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
        int matrix[n][n];
        vector<int> result;
        // read input
        for(int i =0; i < n ; i++)
            for (int j = 0; j < n; j++)
                cin>>matrix[i][j];

        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;

        while (r1<=r2 && c1 <= c2)
        {
            // top
            for(int c = c1; c <= c2; c++) result.push_back(matrix[r1][c]);
            // right
            for(int r = r1 + 1; r <= r2; r++) result.push_back(matrix[r][c2]);

            if(r1 < r2 && c1 < c2){
                // down
                for(int c = c2-1; c > r1; c--) result.push_back(matrix[r2][c]);
                // left
                for(int r = r2; r > r1; r--) result.push_back(matrix[r][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }

        for(auto res : result){
            cout<<res<<" ";
        }
        cout<<"\n";
    }
    return 0;
}