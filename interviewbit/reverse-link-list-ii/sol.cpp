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

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = head;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseBetween(ListNode* A, int m, int n){
    if(m == n) return A;
    ListNode* temp = A, *prev = NULL, *first = A, *last = A;
    int i = 1;
    for(; i < m; i++){
        prev = temp;
        temp = temp->next;
    }

    first = temp;

    for(; i < n; i++)
        temp = temp->next;

    last = temp;

    ListNode * next = last->next;
    last->next = NULL;

    first = reverse(first);

    if(prev != NULL) prev->next = first;
    else A = first;

    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = next;

    return A;
    
    
}
int main(){
    return 0;
}