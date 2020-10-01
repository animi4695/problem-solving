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

ListNode* reverseList(ListNode* A, int B) {
    if(B == 1) return A;

    ListNode* curr = A;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    int count = 0;

    while (count < B && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        A->next = reverseList(next, B);
    }
    return prev;
}

int main(){
    return 0;
}