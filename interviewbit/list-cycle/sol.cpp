#include<iostream>
#include<climits>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

ListNode* detectCycle(ListNode* A){
    if(!A || !A->next) return NULL;

    ListNode* slow = A;
    ListNode* fast = A;

    while(fast != NULL){
        if(fast->next == NULL || fast->next->next == NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) break;
    }

    slow = A;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main(){

    return 0;
}