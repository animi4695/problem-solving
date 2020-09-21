#include<iostream>
#include <limits>

using namespace std;

void interleavings(char res[], string a, string b, int idx, int idxa, int idxb){

    // Base Condition
    if(a.length() + b.length() == idx){
        cout<<res<<"\n";
        return;
    }

    // Main Logic
    if(idxa < a.length() && idxb < b.length()){
        // both string indices are not reached end...
        // to maintain lexicographical order...
        if(a[idxa] < b[idxb]){
            res[idx] = a[idxa];
            interleavings(res, a, b, idx+1, idxa+1, idxb);
            res[idx] = b[idxb];
            interleavings(res, a, b, idx+1, idxa, idxb+1);
        }
        else{
            res[idx] = b[idxb];
            interleavings(res, a, b, idx+1, idxa, idxb+1);
            res[idx] = a[idxa];
            interleavings(res, a, b, idx+1, idxa+1, idxb);
        }
    }
    
    if(a.length() == idxa){
        // string a, reached end...
        res[idx] = b[idxb];
        interleavings(res, a, b, idx+1, idxa, idxb+1);
    }
    
    if(b.length() == idxb){
        // string b, reached end...
        res[idx] = a[idxa];
        interleavings(res, a, b, idx+1, idxa+1, idxb);
    }
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        string a;
        string b;
        cin>>a>>b;
        cout<<"Case #"<<i+1<<":\n";
        char res[a.length()+b.length()+1] = "";
        interleavings(res, a, b, 0, 0, 0);
    }
    
    return 0;
}