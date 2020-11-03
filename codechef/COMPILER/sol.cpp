#include <iostream>
#include <string>
#include<vector>
#include<stack>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string input;
        std::cin >> input;
        std::stack<char> V;
        int ans = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if(input[i] == '<'){
                V.push(input[i]);
            }
            else{
                if(!V.empty()){
                    V.pop();
                    if(V.empty())
                        ans = i+1;
                }
                else
                    break;
            }
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}