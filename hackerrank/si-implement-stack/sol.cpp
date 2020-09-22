#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXSIZE 10001

class Stack{
    public:
        int top;
        int A[MAXSIZE];
        Stack() { top = -1; }
        void push(int x);
        int pop();
        bool isempty();
        bool isfull();
};
bool Stack::isfull() {
   if(top == MAXSIZE)
      return true;
   else
      return false;
}
bool Stack::isempty() {
   if(top == -1)
      return true;
   else
      return false;
}

void Stack::push(int x){
    if(!isfull()) {
      top = top + 1;   
      A[top] = x;
    } else {
      cout<<"Could not insert data, Stack is full.\n";
    }
}

int Stack::pop(){
    if(!isempty()) {
      int ele = A[top];
      top = top - 1;   
      return ele;
    } else {
      return INT_MIN;
    }
}

int main(){
    int t;
    cin>>t;
    Stack s;
    while (t--)
    {
        string a;
        int x;
        cin>>a;
        if(a == "push"){
            cin>>x;
            s.push(x);
        }
        else if(a == "pop"){
            int res = s.pop();
            if(res == INT_MIN) cout<<"Empty\n";
            else{
                cout<<res<<"\n";
            }
        }
    }
    
    return 0;
}