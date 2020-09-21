#include<iostream>
#include <limits>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n1,m1;
        cin>>n1>>m1;
        int matA[n1][m1];

        // read input matrix A
        for(int i = 0 ; i < n1; i++){
            for(int j = 0 ; j < m1; j++){
                cin>>matA[i][j];
            }
        }

        int n2,m2;
        cin>>n2>>m2;
        int matB[n2][m2];

        // read input matrix B
        for(int i = 0 ; i < n2; i++){
            for(int j = 0 ; j < m2; j++){
                cin>>matB[i][j];
            }
        }

        if(m1 != n2) return -1;

        int matR[n1][m2];

        // init result matrix
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < m2; j++)
                matR[i][j] = 0;

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                for (int k = 0; k < m1; k++)
                {
                    matR[i][j] += (matA[i][k] * matB[k][j]);
                    // cout<<matR[i][j]<<"<->";
                } 
                // cout<<"\n";
            }
        }

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                cout<<matR[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    
    return 0;
}