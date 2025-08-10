#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val): data(val), next(NULL){}

};

class CircularLL {
public: 
    Node* head;
    Node* tail;

    CircularLL() : head(NULL), tail(NULL) {}

    void IAH(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        } 
        else {
            newNode->next=head;
            head=newNode;
            tail->next=head; // Maintain circular link
        }
    }
    
    void IAT(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head; // circular link
    } 
    else {
        tail->next = newNode; // old tail points to new node
        newNode->next = head; // new node points to head
        tail = newNode;       // update tail
    }
    }

    void DAF(){
        if(head == NULL) return; // List is empty
        else if(head==tail){
            delete head; // Only one node
            head = tail = NULL;    
        }
        else{
        Node* temp = head;
        head= head->next;
        tail->next=head;

        temp->next=NULL;
        delete temp;
        }
        
    }

    void DAB(){
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head = tail = NULL;
        }
        else {
            Node* temp = tail;
            Node* prev = head;

            while(prev->next!=tail){
                prev->next= tail;
                tail=prev;
                tail->next=head; // Maintain circular link
                temp->next=NULL;
                delete temp;
            }
        }
    }



    void print(){
        if(head==NULL) return;

        cout<< head->data << "->";
        Node* temp = head->next;

        while(temp!=head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<< head->data <<endl;
    }
};

int main() {
    CircularLL cll;
    cll.IAH(10);
    cll.IAH(20);
    cll.IAT(30);
    cll.IAT(40); 
    cll.DAF();
    cll.DAF();
    cll.DAB();

    cout << "Circular Linked List created." << endl;
    cll.print();
    return 0;
}