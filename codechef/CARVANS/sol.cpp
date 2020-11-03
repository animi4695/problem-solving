#include<iostream>

using namespace std;
int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int speeds[n];

        for(int i = 0 ; i< n; i++){
            cin >> speeds[i];
        }
        
        int max_speed = speeds[0];
        int cars_count = 1;
        for( int i = 1; i< n; i++){
            if(speeds[i] <= max_speed){
                cars_count++;
                max_speed = speeds[i];
            }
        }

        cout << cars_count << endl;
    }
    return 0;
}