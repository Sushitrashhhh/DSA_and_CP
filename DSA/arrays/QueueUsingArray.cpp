#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class QueueUsingArray {
    T *data;
    int firstindex, nextindex, size, capacity;
public:
QueueUsingArray(int s){
    data = new T[s];
    capacity = s;
    firstindex = -1;
    nextindex = 0;
    size = 0;   
}

int getsize() {
    return size;
}

bool isEmpty() {
    return size == 0;
}

void enqueue(T element) {
    if (size == capacity) {
        cout << "Queue is full" << endl;
        return;
    }
    data[nextindex] = element;
    nextindex = (nextindex + 1) % capacity;
    size++;
}

void dequeueVoid() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    firstindex = (firstindex + 1) % capacity;
    size--;
}

T front() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return T(); // Return default value of T
    }
    return data[firstindex];
}

T dequeue(){
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return 0; // Return default value of T
    }   
    
    T ans = data[firstindex];
    firstindex = (firstindex + 1) % capacity;
    size--;
    if (size == 0) {
        firstindex = 0;
        nextindex = 0;
    }
    return ans;
    
}
};


int main() {
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element: " << q.front() << endl; // Should print 10
    cout << "Queue size: " << q.getsize() << endl; // Should print 3
    
    q.dequeueVoid();
    cout << "Front element after dequeue: " << q.front() << endl; // Should print 20
    cout << "Queue size after dequeue: " << q.getsize() << endl; // Should print 2
    
    return 0;
}