#include<iostream>
#include<cmath>

using namespace std;
int getDigits(int power){
    if(power <= 9){
        return 1;
    }
    else{
        return ceil(power/9.0);
    }
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int pc, pr;
        cin>>pc>>pr;
        int a = getDigits(pc);
        int b = getDigits(pr);
        int count = 0;
        if(a < b){
            cout<<"0 "<<a<<"\n";
        }
        else {
            cout<<"1 "<<b<<"\n";
        }
    }
    
    return 0;
}