////////////////////Stack//////////////////////////////
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
class Stack {
private:
   Node<T>* topNode;
   int size;

public:
   Stack() : topNode(nullptr), size(0) {}

   void push(T element) {
       Node<T>* newNode = new Node<T>(element);
       newNode->next = topNode;
       topNode = newNode;
       size++;
   }

   T pop() {
       if (isEmpty()) {
           cout << "Stack is empty, cannot pop.\n";
           return T(); 
       }
       Node<T>* temp = topNode;
       T poppedValue = topNode->data;
       topNode = topNode->next;
       delete temp;
       size--;
       return poppedValue;
   }

   T top() {
       if (isEmpty()) {
           cout << "Stack is empty, top element does not exist.\n";
           return T(); 
       }
       return topNode->data;
   }

   bool isEmpty() {
       return topNode == nullptr;
   }

   
   int stackSize() {
       return size;
   }

   
   void clear() {
       while (!isEmpty()) {
           pop();
       }
   }

   
   void print() {
       if (isEmpty()) {
           cout << "Stack is empty.\n";
           return;
       }
       Node<T>* current = topNode;
       while (current != nullptr) {
           cout << current->data << " ";
           current = current->next;
       }
       cout << endl;
   }

};

int main() {
   Stack<int> myStack;

   myStack.push(5);
   myStack.push(10);
   myStack.push(15);

   cout << "Stack: ";
   myStack.print(); 

   cout << "Top element: " << myStack.top() << endl;

   cout << "Popped element: " << myStack.pop() << endl; 

   cout << "Stack after pop: ";
   myStack.print(); 

   cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl; 

   cout << "Stack size: " << myStack.stackSize() << endl; 

   myStack.clear();

   cout << "Is stack empty after clear? " << (myStack.isEmpty() ? "Yes" : "No") << endl; 
}
