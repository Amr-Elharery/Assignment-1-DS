// Ahmed hussein saad
//20220018
#include <iostream>
using namespace std;
class node{
public:
    int value;
    node* next;
    node* previous;

    node(){
        value = 0;
        this->next = nullptr;
        this->previous = nullptr;
    }

    node(int value, node* next, node* previous){
        this->value = value;
        this->next = next;
        this->previous = previous;
    }
};

class DoubleLinkedList{
    node* head;
    node* tail;
public:
    DoubleLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    void addToFirst(int value){
        node *n = new node(value, head, nullptr);
        if (head == nullptr){
            tail = n;
        }
        head = n;
    }
    void removeFromFirst(){
        if (head!= nullptr){
            head = head->next;
            if (head!= nullptr){
                head->previous = nullptr;
            }
        }
        else{
            tail = nullptr;
        }
        if (head == nullptr){
            tail = nullptr;
        }
        else{
            head->previous = nullptr;
        }

    }
    void addToLast(int value){
        if (head == nullptr){
            addToFirst(value);
            return;
        }
        node *n = new node(value, nullptr, tail);
        tail->next = n;
        tail = n;

    }
    void removeFromLast(){
        if (tail!= nullptr){
            tail = tail->previous;
            if (tail!= nullptr){
                tail->next = nullptr;
            }
        }
        else{
            head = nullptr;
        }
        if (tail == nullptr){
            head = nullptr;
        }
        else{
            tail->next = nullptr;
        }

    }
    void insertatindex(int value, int index){
        if (index == 0){
            addToFirst(value);
            return;
        }
        node *n = new node(value, nullptr, nullptr);
        node *temp = head;
        for (int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        n->next = temp->next;
        n->previous = temp;
        temp->next = n;
        if (n->next!= nullptr){
            n->next->previous = n;
        }
        else{
            tail = n;
        }
    }
    void removeFromIndex(int index){
        if (index == 0){
            removeFromFirst();
            return;
        }
        node *temp = head;
        for (int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        if (temp->next!= nullptr){
            temp->next->previous = temp;
        }
        else{
            tail = temp;
        }
    }
    void isItemAtEqual(int index, int value){
        node *temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        if (temp->value == value){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
        
    }
    void retrieveindex(int index){
        node *temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        cout << temp->value << endl;
    }
    void swap(int firstindex, int secondindex){
        node *first = head;
        node *second = head;
        for (int i = 0; i < firstindex; i++){
            first = first->next;
        }
        for (int i = 0; i < secondindex; i++){
            second = second->next;
        }
        int temp = first->value;
        first->value = second->value;
        second->value = temp;
    }
    void size(){
        int count = 0;
        node *temp = head;
        while (temp!= nullptr){
            count++;
            temp = temp->next;
        }
        cout << count << endl;
    }
    void search(int value){
        node *temp = head;
        while (temp!= nullptr){
            if (temp->value == value){
                cout << "found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "not found" << endl;
    }
    void isEmpty(){
        if (head == nullptr){
            cout << "empty" << endl;
        }
        else{
            cout << "not empty" << endl;
        }
    }

    void print(){
        node *p = head;
        while (p != nullptr){
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main(){
  DoubleLinkedList d;
  d.addToFirst(1);
  d.addToFirst(2);
  d.addToFirst(3);
  d.addToFirst(7);
  d.addToFirst(4);
 d.size();
}