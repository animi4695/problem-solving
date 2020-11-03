#include<iostream>
#include<string>
#include<stack>

int precidence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;  
}

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::string stmt;
        std::cin>>stmt;
        std::stack<char> stck;
        for(int i = 0 ;i< stmt.size(); i++){
            if(stmt[i] >= 'A' && stmt[i] <= 'Z'){
                std::cout<<stmt[i];
            }
            else if(stmt[i] == '('){
                stck.push(stmt[i]);
            }
            else if(stmt[i] == ')'){
                while (stck.top() != '(')
                {
                    char c = stck.top();
                    std::cout<<c;
                    stck.pop();
                }

                if(stck.top() == '('){
                    stck.pop();
                }   
            }
            else{
                while(!stck.empty() &&  precidence(stmt[i]) <= precidence(stck.top())){
                    char c = stck.top();
                    stck.pop();
                    std::cout<<c;
                }
                stck.push(stmt[i]);
            }
        }

        while(!stck.empty()){
            std::cout<<stck.top();
            stck.pop();
        }
        std::cout<<std::endl;
    }
    return 0;
}