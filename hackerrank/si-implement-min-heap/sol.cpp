#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
class MinHeap {
private:
    vector<int> v;
    int parent(int i){
        return (i-1)/2;
    }

    int leftchild(int i){
        return (2*i)+1;
    }

    int rightchild(int i){
        return (2*i)+2;
    }

    void heapifyDown(int i){
        // node at index i and two children violates heap property

        // get left and right child of nodes at index i
        int left = leftchild(i);
        int right = rightchild(i);
        int smallest = i;
        
        // compare v[i] with left and right child and find smallest value
        if(left < size() && v[left] < v[i]) smallest = left;
        if(right < size() && v[right] < v[smallest]) smallest = right;

        if(smallest != i){
            swap(v[i], v[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i){
        // check if node at index i and parent violates heap property
        if(i && v[parent(i)] > v[i]){
            swap(v[i], v[parent(i)]);
            heapifyUp(parent(i));
        }
    }

public:
    int size(){
        return v.size();
    }

    bool empty(){
        return size() == 0;
    }

    int getMin(){
        if(v.size() == 0) return INT_MIN;
        return v[0];
    }

    void insert(int x){
        v.push_back(x);
        int idx = size()-1;
        heapifyUp(idx);
    }

    void deleteMin(){
        if(v.size() == 0) return;
        v[0] = v.back();
        v.pop_back();
        heapifyDown(0);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    MinHeap minheap;
    while (t--)
    {
        string s;
        int n;
        cin>>s;
        if(s == "insert"){
            cin>>n;
            minheap.insert(n);
        }
        else if(s == "getMin"){
            int val = minheap.getMin();
            if(val == INT_MIN) cout<<"Empty\n";
            else cout<<minheap.getMin()<<"\n";
        }
        else if(s == "delMin"){
            minheap.deleteMin();
        }
    }
    
    return 0;
}