//Definition for a Node.
#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* next = curr->next;          // store the next pointer
                Node* childHead = flatten(curr->child); // flatten the child list
                
                // connect current node to child
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;            // remove child pointer
                
                // move to the end of the flattened child list
                Node* tail = childHead;
                while (tail->next) tail = tail->next;
                
                // connect tail to the original next
                if (next) {
                    tail->next = next;
                    next->prev = tail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
