#include<iostream>
#include<climits>
#include<string>

using namespace std;
bool isAplhanumeric(char ch){
    if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return true;

    return false;
}

int isPalindrome(string A){
    // 2-ptr technique with omitting extra results other than alphanumeric
    int i = 0;
    int j = A.length()-1;

    while (i<=j)
    {
        if(!isAplhanumeric(A[i])){
            ++i;
            continue;
        }

        if(!isAplhanumeric(A[j])){
            --j;
            continue;
        }

        if(A[i] != A[j] && abs(A[i]-A[j]) != 32) return 0;

        i++;
        j--;
    }
    return 1;
}

int main(){
    string A;
    getline(cin, A);
    cout<<isPalindrome(A);
    return 0;
}