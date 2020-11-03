#include<iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int h,p;
        cin>>h>>p;
        while (p > 0)
        {
            h = h -p;
            if(h <=0){
                cout<<1<<"\n";
                break;
            }
            p = p/2;
        }
        if(p <= 0)  cout<<"0\n";
    }
    
    return 0;
}