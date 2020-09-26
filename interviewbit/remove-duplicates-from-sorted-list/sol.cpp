#include<iostream>
#include<climits>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* deleteDuplicates(ListNode* A){
    ListNode* curr = A;
    while (curr && curr->next)
    {
        if(curr->val == curr->next->val) {
            curr->next = curr->next->next;
        }
        else {
            curr = curr->next;
        }
    }
    return A;
}

int main(){

    return 0;
}