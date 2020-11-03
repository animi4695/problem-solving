#include<iostream>
#include<climits>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val){
        val = val;
        next = NULL;
    }
};

void InsertionSort(ListNode* &head, ListNode* newNode){
    ListNode* curr;
    if(head == NULL || head->val >= newNode->val){
        newNode->next = head;
        head = newNode;
    }
    else{
        curr = head;
        while (curr->next != NULL && curr->next->val < newNode->val)
            curr = curr->next;
        
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

ListNode* insertionSortList(ListNode* A){
    if(A == NULL) return A;
    ListNode* curr = A;
    ListNode* sorted = NULL;

    while (curr != NULL)
    {
        ListNode* next = curr->next;
        InsertionSort(sorted, curr);
        curr = next;
    }
    A = sorted;
    return A;
}

int main(){
    return 0;
}