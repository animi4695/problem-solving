#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXSIZE 10001

class DeQueue{
    public:
        int front;
        int rear;
        int A[MAXSIZE];
        int cnt;
        DeQueue() { front = MAXSIZE-1; rear = 0; cnt = 0; }
        void push_back(int x);
        int pop_back();
        void push_front(int x);
        int pop_front();
        bool isempty();
        bool isfull();
};
bool DeQueue::isfull() {
   if((front == 0 && rear == MAXSIZE-1))
      return true;
   else
      return false;
}
bool DeQueue::isempty() {
   if(front == -1 || front > rear)
      return true;
   else
      return false;
}

void DeQueue::push_front(int x){
    if(cnt != MAXSIZE){
        A[front] = x;
        front = (front-1+MAXSIZE)%MAXSIZE;
        ++cnt;
    }
}

void DeQueue::push_back(int x){
    if(cnt != MAXSIZE){
        A[rear] = x;
        rear = (rear+1)%MAXSIZE;
        ++cnt;
    }
}

int DeQueue::pop_front(){
    if(cnt != 0){
        int ele = A[(front+1)%MAXSIZE];
        front = (front+1)%MAXSIZE;
        --cnt;
        return ele;
    }
    return INT_MIN;
}

int DeQueue::pop_back(){
    if(cnt != 0){
        int ele = A[(rear - 1 + MAXSIZE) % MAXSIZE];
        rear = (rear - 1 + MAXSIZE) % MAXSIZE;
        --cnt;
        return ele;
    }
    return INT_MIN;
}

int main(){
    int t;
    cin>>t;
    DeQueue q;
    while (t--)
    {
        string a;
        int x;
        cin>>a;
        if(a == "push_back"){
            cin>>x;
            q.push_back(x);
        }
        else if(a == "pop_front"){
            int ele = q.pop_front();
            ele == INT_MIN ? cout<<"Empty\n" : cout<<ele<<"\n";
        }
        else if(a == "push_front"){
            cin>>x;
            q.push_front(x);
        }
        else if(a == "pop_back"){
            int ele = q.pop_back();
            ele == INT_MIN ? cout<<"Empty\n" : cout<<ele<<"\n";
        }
    }
    
    return 0;
}