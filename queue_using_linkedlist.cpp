#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class queue
{
private:
    node *front;
    node *rear;

public:
    queue()
    {
        front = rear = NULL;
    }

    int empty(void)
    {
        if (front == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int peek(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        return front->data;
    }

    void enqueue(int x)
    {
        node *p = new node(x);

        if (front == NULL)
        {
            front = p;
            rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }

    int dequeue(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        int x = front->data;
        node *p = front;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete p;

        return x;
    }

    void display(void)
    {
        node *q = front;

        cout << "\nQueue elements: ";

        while (q != NULL)
        {
            cout << "\t" << q->data;
            q = q->next;
        }
    }
};

int main()
{
    int value;
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    q.display();

    if (!q.empty())
    {
        value = q.dequeue();
        cout << "\nDeleted element: " << value;
    }

    q.display();

    value = q.peek();
    cout << "\nFront element is: " << value;

    return 0;
}

//output:

/* > cd "d:\sk\" ; if ($?) { g++ queue_using_linkedlist.cpp -o queue_using_linkedlist } ; if ($?) { .\queue_using_linkedlist }

Queue elements:         10      20      30      40      50      60      70      80
Deleted element: 10
Queue elements:         20      30      40      50      60      70      80
Front element is: 20
PS D:\sk> */