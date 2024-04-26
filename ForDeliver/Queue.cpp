//////////////////////////Queue////////////////////////////////////
#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
   T data;
   Node* next;

   Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class Queue {
private:
   Node<T>* frontNode;
   Node<T>* rearNode;
   int size;

public:
   Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

   void enqueue(T element) {
       Node<T>* newNode = new Node<T>(element);
       if (isEmpty()) {
           frontNode = newNode;
       }
       else {
           rearNode->next = newNode;
       }
       rearNode = newNode;
       size++;
   }

   
   T dequeue() {
       if (isEmpty()) {
           cout << "Queue is empty, cannot dequeue.\n";
           return T(); 
       }
       Node<T>* temp = frontNode;
       T dequeuedValue = frontNode->data;
       frontNode = frontNode->next;
       delete temp;
       if (frontNode == nullptr) {
           rearNode = nullptr;
       }
       size--;
       return dequeuedValue;
   }

   T first() {
       if (isEmpty()) {
           cout << "Queue is empty, front element does not exist.\n";
           return T(); 
       }
       return frontNode->data;
   }

   
   bool isEmpty() {
       return frontNode == nullptr;
   }

   
   int queueSize() {
       return size;
   }

   void clear() {
       while (!isEmpty()) {
           dequeue();
       }
   }

   void print() {
       if (isEmpty()) {
           cout << "Queue is empty.\n";
           return;
       }
       Node<T>* current = frontNode;
       while (current != nullptr) {
           cout << current->data << " ";
           current = current->next;
       }
       cout << endl;
   }
};

int main() {
   Queue<int> myQueue;

   myQueue.enqueue(5);
   myQueue.enqueue(10);
   myQueue.enqueue(15);

   cout << "Queue: ";
   myQueue.print(); 

   cout << "Front element: " << myQueue.first() << endl;

   cout << "Dequeued element: " << myQueue.dequeue() << endl; 

   cout << "Queue after dequeue: ";
   myQueue.print(); 

   cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl; 

   cout << "Queue size: " << myQueue.queueSize() << endl;
   myQueue.clear();

   cout << "Is queue empty after clear? " << (myQueue.isEmpty() ? "Yes" : "No") << endl; 
}
