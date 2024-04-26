// Ahmed hussein saad
//20220018
#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node()
    {
        this->value = 0;
        this->next = NULL;
    }
    node(int value, node *next)
    {
        this->value = value;
        this->next = next;
    }
};

class linkedList
{
private:
    node *head;

public:
    linkedList()
    {
        this->head = NULL;
    }
    void addtofirst(int value)
    {
        node *newnode = new node(value, this->head);
        this->head = newnode;
    }
    void removefromfirst()
    {
        if (head == NULL)
            return;
        head = head->next;
    }
    void addtolast(int value)
    {
        if (head == NULL)
        {
            this->addtofirst(value);
            return;
        }
        
        node *newnode = new node(value, NULL);
        node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newnode;
    }
    void removefromlast(){
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
           delete head;
           head = NULL;
            return;
        }
        node* p = head;
        node* pa =head;
        while (p->next!= NULL)
        {
            pa = p;
            p = p->next;
        }
        delete p;
        pa->next = NULL;
    }
    int size(){
        int count = 0;
        node* p = head;
        while (p!= NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }
    void addtoindex(int value, int index){
        if (head == NULL)
        {
            this->addtofirst(value);
            return;
        }
        if (index == 0)
        {
            this->addtofirst(value);
            return;
        }
        node* newnode = new node(value, NULL);
        node* p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        newnode->next = p->next;
        p->next = newnode;
    }
    void removefromindex(int index){
        if (head == NULL)
            return;
        if (index == 0)
        {
            this->removefromfirst();
            return;
        }
        node* p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        node* pa = p->next;
        p->next = pa->next;
        delete pa;
    }
    
    int retrieveindex(int index){                            
        if (head == NULL)                                    
            return -1;                                      
        node* p = head;                                    
        for (int i = 0; i < index; i++)                      
        {                                                   
            p = p->next;                                     
        }                                                    
        return p->value;                                     
    }                                                        
    
  int replacAt( int index, int value){
    if (head == NULL)
        return -1;
    node* p = head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    int temp = p->value;
    p->value = value;
    return temp;
  }
   
    void search(int value){
        node* p = head;
        while (p!= NULL)
        {
            if (p->value == value)
            {
                cout << "found" << endl;
                return;
                
            }
            p = p->next;
        }
        cout << "not found" << endl;
        return;
    }
    bool isItemAtEqual(int value , int index){
        if (head == NULL)
            return false;
        node* p = head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        if (p->value == value)
            return true;
        return false;
    }
    
    void swap (int firstindex, int secondindex) { 
        if (head == NULL)
            return;
        if (firstindex == secondindex)
            return;
        if (firstindex > secondindex)
        {
            int temp = firstindex;
            firstindex = secondindex;
            secondindex = temp;
        }
        node* p = head;
        node* pa = head;
        for (int i = 0; i < firstindex; i++)
        {
            pa = p;
            p = p->next;
        }
        node* q = head;
        node* qa = head;
        for (int i = 0; i < secondindex; i++)
        {
            qa = q;
            q = q->next;
        }
        int temp = p->value;
        p->value = q->value;
        q->value = temp;
        
    }
    bool isEmpty(){
        return head == NULL;
    }
     void print(){
        node* p = head;
        while (p!= NULL)
        {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
    void clear(){
        while (head!= NULL)
        {
            this->removefromfirst();
        }
    }
};
int main()
{
    linkedList l;
    l.addtofirst(10);
    l.addtofirst(11);
    l.addtofirst(12);
    l.addtofirst(13);
    l.addtofirst(14);
    l.addtofirst(15);
    l.addtofirst(16);
    l.addtofirst(17);
    l.addtofirst(18);
    l.addtofirst(19);
    l.addtofirst(20);
    l.addtofirst(21);
    l.addtofirst(22);
    cout<<l.retrieveindex(0);
   
}