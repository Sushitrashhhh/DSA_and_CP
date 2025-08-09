#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DL {
public:
    Node* head;
    Node* tail;

    DL() : head(nullptr), tail(nullptr) {}

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        cout << "Inserted " << val << " at the front." << endl;
    }
    
    void push_back(int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop_front(int val){
        Node* temp = head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }


    void pop_back(int val){
        Node*temp = tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }




    void print() {
        Node* temp= head;
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

// This code defines a doubly linked list with basic structure and initialization.


int main() {
    DL dll;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(30);
    dll.push_back(400);
    dll.push_back(500);
    dll.pop_front(10); // This will remove the first element (10)
    dll.pop_back(500); // This will remove the last element (500)
    dll.pop_front(20); // This will remove the second element (20)
    dll.print(); // Expected output: 30 <-> 20 <-> 10 <-> NULL

    return 0;
}