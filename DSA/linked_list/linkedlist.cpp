#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;  // List became empty
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        temp->next = NULL;
        tail = temp;
    }

    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position out of bounds" << endl;
                return;
            }
            temp = temp->next;
        } 

        if (temp == NULL) { // Fix: check if temp is NULL before inserting
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;  // Update tail if inserted at the end
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int search(int key) {
        Node* temp = head;
        int index = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                return index; // Return the index of the found value
            }
            temp = temp->next;
            index++;
        }
        return -1; // Value not found
    }
};

int main() {
    List myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);     // List: 30 -> 20 -> 10
    myList.push_back(400);     // List: 30 -> 20 -> 10 -> 400

    myList.pop_front();        // List: 20 -> 10 -> 400
    myList.pop_back();         // List: 20 -> 10
    myList.insert(25, 1);      // List: 20 -> 25 -> 10

    cout << myList.search(25) << endl; // Output: 1
    cout << "Linked List created successfully." << endl;
    myList.print();            // Output: 20->25->10->NULL

    return 0;
}
