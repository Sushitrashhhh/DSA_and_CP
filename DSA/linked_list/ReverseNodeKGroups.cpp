// Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(count<k){
            if(temp==NULL) return head;
            temp=temp->next;
            count++;
        }
        ListNode* prev = reverseKGroup(temp, k);
        temp=head; count=0;
        while(count<k){
            ListNode* next= temp->next;
            temp->next=prev;

            prev=temp;
            temp=next;
            
            count++;
        }
        return prev;
    }
};