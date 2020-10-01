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

ListNode* swap(ListNode* next1, ListNode* next2){
    next1->next = next2->next;
    next2->next = next1;
    return next2;
}

ListNode* swapPairs1(ListNode* A){
    // create a dummy node
    ListNode* dummy = new ListNode(0);
    dummy->next = A;

    ListNode* curr = dummy;

    while (curr->next != NULL && curr->next->next != NULL)
    {
        curr->next = swap(curr->next, curr->next->next);
        // take another pair now...
        curr = curr->next->next;
    }
    return dummy->next;
}

ListNode* swapPairs(ListNode* A) {
    if(A == NULL || A->next == NULL) return A;
    ListNode* head = A->next;
    ListNode* prev = NULL;

    while (A != NULL && A->next != NULL)
    {
        ListNode* temp = A->next;
        // 1st node linking to 3rd node
        A->next = A->next->next;
        // 2nd node linking to 1st node
        temp->next = A;

        if(prev != NULL) prev->next = temp;
        prev = A;

        A = A->next;
    }

    return head;
}

int main(){
    return 0;
}