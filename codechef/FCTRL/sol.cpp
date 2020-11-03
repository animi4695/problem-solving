#include <iostream>
#include <cmath>

using namespace std;
int main(){

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;

        int count = 0;
        int i = 1;
        while(n/pow(5,i) > 0){
            count = count + floor(n/pow(5,i));
            i ++;
        }
        cout << count << endl;
    }
    
    return 0;
}