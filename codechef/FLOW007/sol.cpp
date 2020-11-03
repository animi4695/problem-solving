#include <iostream>

using namespace std;
int reverse(int n);

int main()
{

    int t;
    int n;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        reverse(n);
        cout << endl;
    }

    return 0;
}

int reverse(int n)
{
    int temp = n;
    int count = 0;
    // Ignore starting 0s. wait until you see a digit > 0
    while(n%10 == 0){
        n = n/10;
    }
    while (n > 0)
    {
        cout << n % 10;
        n = n / 10;
    }
    return 0;
}