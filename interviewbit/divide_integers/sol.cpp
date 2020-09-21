#include<iostream>
#include <climits>

using namespace std;
int divide(int A, int B);
int main(){
    cout<<divide(-1,1);
    return 0;
}

int divide(int A, int B) {
    // https://www.youtube.com/watch?v=bdxJHWIyyqI
    long long dividend = A;
    long long divisor = B;

    int sign = (dividend<0)^(divisor<0)? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    long long q = 0;
    long long t = 0; // temp to hold previous values;
    for(long long i = 31; i>=0; i--){
        if(t + (divisor<<i) <= dividend){
            t = t + (divisor<<i);
            q = q | ((long long)1<<i);
        }
    }

    if(sign < 0) q = -q;

    return (q >=INT_MAX || q < INT_MIN) ? INT_MAX : q;
}