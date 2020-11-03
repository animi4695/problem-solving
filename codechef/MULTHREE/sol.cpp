#include <iostream>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int k, d0, d1;
        cin >> k >> d0 >> d1;
        long long int sum = 0;
        // follows cyclicity of 2 is 4(2,4,6,8) and its sum is 20
        if(k == 2){
            sum = d0+d1;
        }
        else if(k==3){
            sum = d0+d1 + ((d0+d1)%10);
        }
        else{
            int a,b,c,d;
            a= (2 * (d0+d1))%10;
            b= (4 * (d0+d1))%10;
            c= (8 * (d0+d1))%10;
            d= (6 * (d0+d1))%10;
            sum = ((d0+d1) + (d0+d1)%10) + ((a+b+c+d) * ((k-3)/4));
            if((k-3)%4 == 1){
                sum = sum + a;
            }
            else if((k-3)%4 == 2){
                // cout<<sum<<endl;
                sum = sum + a + b;
            }
            else if((k-3)%4 == 3){

                sum = sum + a + b + c;
            }
        }
        // cout << sum << endl;
        if(sum%3 == 0){
            cout << "YES" <<endl;
        }
        else{
            cout << "NO" << endl;
        }
        // ---- NAIVE Sol ------------
        // long long int sum = d0 + d1;
        // for(int i = 2; i< k; i++){
        //     int temp = sum;
        //     sum = sum + temp%10;
        // }
        // if(sum%3 == 0){
        //     cout << "YES" << endl;
        // }
        // else{
        //     cout << "NO" << endl;
        // }
        // --------------------------
    }

    return 0;
}