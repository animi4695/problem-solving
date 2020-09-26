#include<iostream>
#include<climits>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* mergeTwoLists(ListNode* A, ListNode* B){
    if(!A) return B;
    if(!B) return A;

    ListNode* res = new ListNode(0);
    ListNode* dummy = res;
    while (A && B)
    {
        if(A->val <= B->val){
            res->next = A;
            A = A->next;
        }
        else{
            res->next = B;
            B = B->next;
        }
        res = res->next;
    }

    while(A){
        res->next = A;
        A= A->next;
        res = res->next;
    }

    while(B){
        res->next = B;
        B = B->next;
        res = res->next;
    }
    return dummy->next;
}
int main(){
    return 0;
}