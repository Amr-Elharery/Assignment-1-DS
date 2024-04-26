////////////////////////Circular LinkedList///////////////////////////////////
#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtHead(T element) {
        Node<T>* new_node = new Node<T>(element);
        if (!head) {
            new_node->next = new_node;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
        head = new_node;
    }

    void insertAtTail(T element) {
        Node<T>* new_node = new Node<T>(element);
        if (!head) {
            new_node->next = new_node;
            head = new_node;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    void insertAt(T element, int index) {
        if (index == 0) {
            insertAtHead(element);
        }
        else {
            Node<T>* new_node = new Node<T>(element);
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void removeAtHead() {
        if (!head) {
            return;
        }
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }

    void removeAtTail() {
        if (!head) {
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        temp->next = head;
    }

   void removeAt(int index) {
    if (!head) {
        return; // Empty list
    }

    if (index == 0) {
        removeAtHead();
        return;
    }

    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    int count = 0;

    // Traverse until the node at index or until the end of the list
    while (count < index && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If index exceeds the size of the list, do nothing
    if (count != index) {
        return;
    }

    // Remove the node at index
    prev->next = temp->next;
    delete temp;
    }



    T retrieveAt(int index) {
        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    void replaceAt(T new_element, int index) {
        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        temp->data = new_element;
    }

    bool isExist(T element) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == element) {
                return true;
            }
            temp = temp->next;
            if (temp == head) {
                break;
            }
        }
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        return retrieveAt(index) == element;
    }

    void swap(int first_item_idx, int second_item_idx) {
        if (first_item_idx == second_item_idx) {
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < first_item_idx; ++i) {
            temp = temp->next;
        }
        Node<T>* first_node = temp;
        for (int i = 0; i < second_item_idx - first_item_idx; ++i) {
            temp = temp->next;
        }
        Node<T>* second_node = temp;

        std::swap(first_node->data, second_node->data);
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int linkedListSize() {
        int count = 0;
        Node<T>* temp = head;
        while (temp) {
            ++count;
            temp = temp->next;
            if (temp == head) {
                break;
            }
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            removeAtHead();
        }
    }

    void print() {
        if (!head) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node<T>* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList<int> list;

    // Insertion tests
    list.insertAtHead(1);
    list.insertAtTail(2);
    list.insertAt(3, 1);
    cout << "After insertion: ";
    list.print(); 

    // Removal tests
    list.removeAtHead();
    list.removeAtTail();
    cout << "After removal: ";
    list.print(); 

    // Replacement test
    list.insertAtHead(4);
    list.insertAtTail(5);
    list.replaceAt(6, 0);
    cout << "After replacement: ";
    list.print(); 

    // Existence tests
    cout << "Is 5 in the list? " << (list.isExist(5) ? "Yes" : "No") << endl; 
    cout << "Is 7 in the list? " << (list.isExist(7) ? "Yes" : "No") << endl; 

    // Size test
    cout << "Size of the list: " << list.linkedListSize() << endl; 
}

