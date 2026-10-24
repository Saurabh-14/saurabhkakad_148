#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* p = new Node(val); 
        if (head == nullptr) {
            head = p;
        } else {
            Node* q = head; 
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
    }

    void remove(int val) {
        Node *p,*q;
               q = head;

                if (q->data == val) {
                p = head;
                head=head->next;
                head->prev=nullptr;
                delete p;
                return;
                }
                
                while (q->next != NULL) {
            if (q->next->data == val) {
                p = q->next;
                q->next = p->next;
                p->next->prev=q;
                delete p;
                return;
            }
            q = q->next;
        }
       
  

        cout << "Value " << val << " not found in the list.\n";
    }

    void displayForward() {
        Node* q = head;
        cout << "Forward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        Node* q = head;
        if (q == nullptr) {
            cout << "Backward: NULL\n";
            return;
        }

        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "Backward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->prev;
        }
        cout << "NULL\n";
    }
};


int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.displayForward();   
    list.displayBackward();  

    list.remove(20);
    list.displayForward();   
    list.displayBackward();  

    return 0;
}

//Output
 
/*PS D:\sk> cd "d:\sk\" ; if ($?) { g++ doubly_linklist.cpp -o doubly_linklist } ; if ($?) { .\doubly_linklist }
Forward: 10 <-> 20 <-> 30 <-> NULL
Backward: 30 <-> 20 <-> 10 <-> NULL
Forward: 10 <-> 30 <-> NULL
Backward: 30 <-> 10 <-> NULL
PS D:\sk>*/ 