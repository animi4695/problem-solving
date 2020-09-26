#include<iostream>
#include<climits>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* A){
    if(!A || !A->next) return A;
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* prev = dummy;

    while (A)
    {
        while(A->next && A->val == A->next->val) A = A->next;

        if(prev->next == A) prev = prev->next;
        else prev->next = A->next;

        A = A->next;
    }
    return dummy->next;
}
int main(){
    return 0;
}