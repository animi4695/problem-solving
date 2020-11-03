#include<iostream>

using namespace std;
int whoWins(long int a, long int b){
    long int sumA = 0;
    while(a>0){
        sumA += a%10;
        a = a/10;
    }

    long int sumB = 0;
    while(b > 0){
        sumB += b%10;
        b = b/10;
    }
    if(sumA > sumB) return 1;
    else if(sumA == sumB) return 0;
    else return 2;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int rounds;
        cin>>rounds;
        int chef = 0;
        int morty = 0;
        for(int i = 0; i<rounds; i++){
            long int a, b;
            cin>>a>>b;
            //Calculate who wins
            int ans = whoWins(a,b);
            if(ans == 1){
                chef++;
            }
            else if(ans == 0){
                chef++;
                morty++;
            }
            else{
                morty++;
            }
        }
        if(chef == morty){
            cout<<2<<" "<<chef;
        }
        else if(chef > morty){
            cout<<0<<" "<<chef;
        }else{
            cout<<1<<" "<<morty;
        }
        cout<<endl;
    }
    
    return 0;
}