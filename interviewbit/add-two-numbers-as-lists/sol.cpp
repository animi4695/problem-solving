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

ListNode* addTwoNumbers(ListNode* A, ListNode* B){
    if(!A) return B;
    if(!B) return A;

    int sum = 0, carry = 0;
    sum = (A->val + B->val + carry);
    ListNode* newHead = new ListNode(sum%10);
    carry = sum/10;
    A = A->next;
    B = B->next;

    ListNode* newHeadPtr = newHead;

    while (A || B || carry)
    {
        sum = (A? A->val : 0) + (B? B->val : 0) + carry;
        ListNode* temp = new ListNode(sum%10);
        carry = sum/10;
        newHead->next = temp;
        newHead = newHead->next;

        if(A) A = A->next;
        if(B) B = B->next;
    }
    return newHeadPtr;
}

int main(){
    return 0;
}