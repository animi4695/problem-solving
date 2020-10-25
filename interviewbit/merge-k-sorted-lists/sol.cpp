#include<iostream>
#include<climits>
#include<vector>
#include<queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct myCustCompare{
    bool operator()(ListNode* const &a, ListNode* const &b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*> &A) {
    if(A.empty()) return NULL;
    priority_queue<ListNode*, vector<ListNode*>, myCustCompare> pq;
    for(int i = 0; i < A.size(); i++){
        if(A[i]) pq.emplace(A[i]);
    }
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    
    while(!pq.empty()){
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;
        if(tail->next){
            pq.emplace(tail->next);
        }
    }
    return dummy->next;
}
int main(){
    return 0;
}