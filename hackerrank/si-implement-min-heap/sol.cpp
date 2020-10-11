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
        return (2*i+1);
    }

    int rightchild(int i){
        return (2*i+2);
    }

    void heapifyDown(int i){
        // node at index i and two children violates heap property

        // get left and right child of nodes at index i
        int left = leftchild(i);
        int right = rightchild(i);
        int smallest = i;
        
        // compare v[i] with left and right child and find smallest value
        if(left < size() && v[left] < v[i]) smallest = left;
        if(right < size() && v[right] < v[i]) smallest = right;

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
        return v[0];
    }

    void insert(int x){
        v.push_back(x);
        int idx = size()-1;
        heapifyUp(idx);
    }

    void deleteMin(){
        v.pop_back();
        heapifyDown(0);
    }
};

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
    }
    
    return 0;
}