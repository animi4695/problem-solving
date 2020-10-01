#include<iostream>
#include<climits>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reverse(ListNode** head_ref){
    ListNode* prev = NULL;
    ListNode* curr = *head_ref;
    while (curr != NULL)
    {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head_ref = prev;
}

int lPalin(ListNode * A){
    ListNode* slowPtr = A;
    ListNode* fastPtr = A;
    ListNode* mid = NULL;
    ListNode* prevSlow = A;

    if(A != NULL && A->next != NULL){
        while (fastPtr != NULL && fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            prevSlow = slowPtr;
            slowPtr = slowPtr->next;
        }

        // unlink mid for odd case
        if(fastPtr != NULL){
            mid = slowPtr;
            slowPtr = slowPtr->next;
        }

        ListNode* secondHalf = slowPtr;
        // terminate 1st half of the list
        prevSlow->next = NULL;

        // reverse the second half
        reverse(&secondHalf);

        // compare both the halves;
        ListNode* head1 = A;

        while (head1 != NULL && secondHalf != NULL)
        {
            if(head1->val != secondHalf->val) return 0;
            head1 = head1->next;
            secondHalf = secondHalf->next;
        }
        if(head1 == NULL && secondHalf == NULL) return 1;
        return 0;
    }
    return 1;
}

int main(){
    return 0;
}