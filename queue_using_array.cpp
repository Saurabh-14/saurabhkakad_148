#include<iostream>
using namespace std;

#define MAX 5

class queue
{
private:
    int a[MAX];
    int front, rear;

public:

    queue()
    {
        front = -1;
        rear = -1;
    }

    int empty()
    {
        if(front == -1)
            return 1;
        else
            return 0;
    }

    int full()
    {
        if(rear == MAX - 1)
            return 1;
        else
            return 0;
    }

    void enqueue(int x)
    {
        if(rear == -1)
            front = 0;

        rear++;
        a[rear] = x;
    }

    int dequeue()
    {
        int x = a[front];

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return x;
    }

    int peek()
    {
        return a[front];
    }

    void display()
    {
        for(int i = front; i <= rear; i++)
            cout << a[i] << "\t"<<endl;
    }
};
int main()
{
    queue q;
    int a[]={10,20,30,40,50,60};
    for(int i=0;i<6;i++)
    {
        if(!q.full())
        {
            q.enqueue (a[i]);
            cout<<"queue elements after enqueue operation"<<endl;
            q.display();
        }
        else
        {
            cout<<"queue is full"<<endl;
        }
    }
    for(int i=0;i<6;i++)
    {
        if(!q.empty())
        {
        cout<<"dequeued element is"<<q.dequeue()<<endl;
        cout<<"queue elements after dequeue operation"<<endl;
        q.display();
        }
        else
        {
            cout<<"queue is empty"<<endl;
        }
    }
}

/*PS C:\Users\HP\Desktop\sk> & C:\Users\HP\Desktop\sk\queue.exe
queue elements after enqueue operation
10
queue elements after enqueue operation
10
20
queue elements after enqueue operation
10
20
30
queue elements after enqueue operation
10
20
30
40
queue elements after enqueue operation
10
20
30
40
50
queue is full
dequeued element is10
queue elements after dequeue operation
20
30
40
50
dequeued element is20
queue elements after dequeue operation
30
40
50
dequeued element is30
queue elements after dequeue operation
40
50
dequeued element is40
queue elements after dequeue operation
50
dequeued element is50
queue elements after dequeue operation
0
queue is empty
PS C:\Users\HP\Desktop\sk> */