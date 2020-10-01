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

ListNode* removeNthFromEnd(ListNode* A, int n){
    int len = 0;
    ListNode* temp = A;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    if(n >= len)
        return A->next;
    
    temp = A;
    for(int i = 0; i < n-len-1; i++) temp = temp->next;

    temp->next = temp->next->next;

    return A;
}

int main(){
    return 0;
}