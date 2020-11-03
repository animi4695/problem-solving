#include<iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        char arr[8][8];
        for(int i = 0 ; i< 8; i++){
            for(int j = 0; j < 8; j++){
                arr[i][j] = 'X';
            }
        }

        int i = 0, j = 0;
        while(n--){
            arr[i][j] = '.';
            j++;
            if(j>7){
                i++;
                j=0;
            }
        }
        arr[0][0] = 'O';

        for(int i = 0 ; i< 8; i++){
            for(int j = 0; j < 8; j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
    
    return 0;
}