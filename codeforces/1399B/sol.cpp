#include<iostream>
#include <limits>

using namespace std;
int main(){
    long long t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        long long arrC[n];
        long long  arrO[n];
        long long minO = INT32_MAX;
        long long minC = INT32_MAX;
        for (long long i = 0; i < n; i++)
        {
            cin>>arrC[i];
            minC = min(arrC[i], minC);
        }

        for (int i = 0; i < n; i++)
        {
            cin>>arrO[i];
            minO = min(minO, arrO[i]);
        }

        int i = 0;
        int j = 0;

        long long result = 0;
        while (i < n && j < n)
        {
            if(arrC[i] > minC && arrO[j] >= minO) {
                result += max(arrO[j] - minO, arrC[i] - minC);
            }
            else if(arrC[i] > minC){
                result += arrC[i] - minC;
            }
            else if(arrO[j] > minO){
                result += arrO[j] - minO;
            }

            i++;
            j++;
        }

        cout<<result<<"\n";   
    }
    
    return 0;
}