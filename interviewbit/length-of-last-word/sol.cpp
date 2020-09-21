#include<iostream>
#include<climits>

using namespace std;
int lengthOfLastWord(const string A){
    int count = 0;
    for(int i = A.length()-1; i >= 0; i--){
        if(isspace(A[i])){
            if(count != 0) return count;
        }
        else{
            count++;
        }
    }
    return count;
}
int main(){
    string A = " ";
    cout<<lengthOfLastWord(A);
    return 0;
}