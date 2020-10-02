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

ListNode* partition(ListNode* A, int B){
    ListNode* temp1 = new ListNode(0);
    ListNode* temp2 = new ListNode(0);

    ListNode* start1 = temp1;
    ListNode* start2 = temp2;

    while(A != NULL){
        if(A->val < B){
            start1->next = A;
            start1 = start1->next;
        }
        else{
            start2->next = A;
            start2 = start2->next;
        }
        A = A->next;
    }

    start1->next = temp2->next;
    start2->next = NULL;
    return temp1->next;
}

int main(){

    return 0;
}