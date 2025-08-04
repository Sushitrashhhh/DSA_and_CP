#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Sol{
public:
    bool hasCycle(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;


        while(fast !=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true; // Cycle detected
            }
        return false; // No cycle detected

        }
    }
};