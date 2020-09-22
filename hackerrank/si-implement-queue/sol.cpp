#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXSIZE 10001

class Queue{
    public:
        int front;
        int rear;
        int A[MAXSIZE];
        Queue() { front = -1; rear = -1; }
        void enqueue(int x);
        int dequeue();
        bool isempty();
        bool isfull();
};
bool Queue::isfull() {
   if(front == 0 && rear == MAXSIZE-1)
      return true;
   else
      return false;
}
bool Queue::isempty() {
    // cout<<rear<<" "<<front;
   if(front == -1 || front > rear)
      return true;
   else
      return false;
}

void Queue::enqueue(int x){
    if(!isfull()) {
        if(front == -1) front = 0;
        rear = (rear+1)%MAXSIZE;
        A[rear] = x;
    } else {
      cout<<"Could not insert data, Stack is full.\n";
    }
}

int Queue::dequeue(){
    if(!isempty()){
        int ele = A[front];
        front = (front + 1) % MAXSIZE;
        return ele;
    }
    return INT_MIN;
}

int main(){
    int t;
    cin>>t;
    Queue s;
    while (t--)
    {
        string a;
        int x;
        cin>>a;
        if(a == "Enqueue"){
            cin>>x;
            s.enqueue(x);
        }
        else if(a == "Dequeue"){
            int res = s.dequeue();
            if(res == INT_MIN) cout<<"Empty\n";
            else{
                cout<<res<<"\n";
            }
        }
    }
    
    return 0;
}