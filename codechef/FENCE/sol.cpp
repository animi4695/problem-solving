#include <iostream>
#include<algorithm>
#include<set>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m, k;
        cin >> n >> m >> k;

        set<pair<int,int>> st;
        for(int i = 0; i< k; i++){
            int a, b;
            cin>>a>>b;
            st.insert({a,b});
        }

        // cout<<endl;
        int fences = 4*st.size();
        for(auto x : st){
            // cout<<x.first<< " " << x.second<<endl;
            if(st.find({x.first, x.second -1 })!= st.end()){
                fences--;
            }

            if(st.find({x.first, x.second + 1 })!= st.end()){
                fences--;
            }

            if(st.find({x.first + 1, x.second })!= st.end()){
                fences--;
            }

            if(st.find({x.first - 1, x.second })!= st.end()){
                fences--;
            }
            
        }

        cout<<fences<<endl;
    }

    return 0;
}