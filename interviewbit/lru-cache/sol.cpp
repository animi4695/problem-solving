#include<iostream>
#include<climits>
#include<unordered_map>

class LRUCache{
struct Node{
  int key;
  int value;
  Node *next;
  Node *prev;
  Node(int key, int value){
      key = key;
      value = value;
      next = NULL;
      prev = NULL;
  }
};

Node* head;
Node* tail;
unordered_map<int, Node*> mp;
int sz;
int cap;

void addNode(Node* node) {
    node->prev = head;
    node->next = head->next;
    
    head->next->prev = node;
    head->next = node;
}

void removeNode(Node* node){
    Node* prev = node->prev;
    Node* next = node->next;
    
    prev->next = next;
    next->prev = prev;
}

void moveToHead(Node* node){
    removeNode(node);
    addNode(node);
}

Node* popTail(){
    Node* res = tail->prev;
    removeNode(res);
    return res;
}

LRUCache::LRUCache(int capacity) {
    sz = 0;
    cap = capacity;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    
    head->next = tail;
    tail->prev = head;
}

int LRUCache::get(int key) {
    auto itr = mp.find(key);
    if(itr == mp.end()) return -1;
    
    moveToHead(itr->second);
    
    return (itr->second)->value;
}

void LRUCache::set(int key, int value) {
    auto itr = mp.find(key);
    if(itr == mp.end()){
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        
        addNode(newNode);
        
        ++sz;
        
        if(sz > cap){
            Node* tail = popTail();
            mp.erase(tail->key);
            --sz;
        }
    }
    else{
        (itr->second)->value = value;
        moveToHead(itr->second);
    }
}

};

using namespace std;
int main(){
    return 0;
}