#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int xbl1, ybl1, xtr1, ytr1;
        int xbl2, ybl2, xtr2, ytr2;

        cin>>xbl1>>ybl1>>xtr1>>ytr1;
        cin>>xbl2>>ybl2>>xtr2>>ytr2;

        long long area1, area2, intersecting_area, result = 0;

        // finding areas of both the rectangles given...
        area1 = (long long)abs(xtr1 - xbl1)* (long long)abs(ytr1-ybl1);
        area2 = (long long)abs(xtr2 - xbl2)* (long long)abs(ytr2-ybl2);

        if(ytr1 <= ybl2 || xtr1 <= xbl2 || ybl1 >= ytr2 || xtr2 < xbl1){
            intersecting_area = 0;
        }
        else{
            // rectangles are overlapping.. find their co-ordinates
            int x = abs(min(xtr1, xtr2) - max(xbl1, xbl2));
            int y = abs(min(ytr1, ytr2) - max(ybl1, ybl2));

            intersecting_area = (long long)x * (long long)y;
        }

        result = area1 + area2 - intersecting_area;

        cout<<result<<"\n";
    }
    
    return 0;
}