#include<iostream>
#include<climits>

using namespace std;
bool isVowel(char ch){
    bool res = true;
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
         res = true;
         break;
    
    default:
        res = false;
        break;
    }

    return res;
}
int solve(string A){
    int count = 0;
    for(int i = 0; i < A.length(); i++){
        if(isVowel(A[i])){
            count += A.length()-i;
        }
    }

    return count%10003;
}
int main(){
    string A = "ABEC";
    cout<<solve(A);
    return 0;
}