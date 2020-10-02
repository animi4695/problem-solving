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

int findLen(ListNode* A){
    int l = 0;
    while(A != NULL){
        A = A->next;
        l++;
    }
    return l;
}

ListNode* rotateRight(ListNode* A, int k) {
    ListNode* head = A;
    int len = findLen(A);

    if(k%len == 0) return head;

    // traverse till rotation point
    for(int i = 0; i < len-k%len-1; i++) head = head->next;

    ListNode* next = head->next;
    head->next = NULL;

    ListNode* last = next;
    while (last->next != NULL) last = last->next;

    last->next = A;
    A = next;

    return A;
}

int main(){
    return 0;
}