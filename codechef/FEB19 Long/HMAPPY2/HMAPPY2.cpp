#include<iostream>
using namespace std;

int main(){
    int T,N,A,B,K,count=0;

    cin>>T;
    for(int i = 0; i < T; i++){
        count = 0;
        cin>>N>>A>>B>>K;
        int j=1;
        while(A*j <= N){
            if((A*j)%B != 0){
                count=count+1;
            }
            j++;
        }
        j=0;
        while(B*j <= N){
            if((B*j)%A != 0){
                count=count+1;
            }
            j++;
        }
        if(count>=K){
                cout<<"Win"<<"\n";
        }else{
            cout<<"Lose"<<"\n";
        }

    }
    return 0;
}
