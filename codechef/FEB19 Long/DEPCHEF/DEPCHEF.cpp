#include<iostream>
using namespace std;

int main(){
    int T,N;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        int A[N],D[N];
        // Read Attacking power of each soldier
        for(int j=0; j<N;j++){
            cin>>A[j];
        }
        // Read Defense Power of each soldier
        for(int j=0; j<N;j++){
            cin>>D[j];
        }
        int count=0;
        int fail = 0;
        int max = D[0];
        int max_index = -1;
        for(int i =0 ;i< N; i++){
            if(D[i] > max ){
             max = D[i];
             D[i] = -1;
             max_index = i;
            }
        }
        if(max_index = 0){
            if(max > A[max_index + 1] + A[N]){
                return max;
            }
            return -1;
        }
        if( max > A[max_index - 1] + A[max_index + 1]){
            return max;
        }

    }
}
