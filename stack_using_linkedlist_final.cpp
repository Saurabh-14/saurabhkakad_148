#include<iostream>
#define MAX 5
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int x){
        data = x;
        next = NULL;
    }
};

class stack
{
    private:
    node *top;


    public:
    stack(){
        top = NULL;
    }


 
int empty(){
    if (top = NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(int x){
    node *p = new node(x);
    p -> next = top;
    top = p;
}

int pop(){
    int x = top -> data;
    node *p = top;
    top = top -> next;
    delete p;
    return x;
}

void display(){
    node *q = top;
    while(q != NULL){
        cout << q -> data << endl;
        q = q -> next;
    }
}
int peek(){
    return (top -> data);
}
};


int main(){

    stack s;
    int x;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.display();

    cout << endl;
    s.pop();
    s.pop();

    s.display();

    
    

    return 0;
}

//output:

 /*> cd "d:\sk\" ; if ($?) { g++ stack_using_linkedlist_final.cpp -o stack_using_linkedlist_final } ; if ($?) { .\stack_using_linkedlist_final }
60
50
40
30
20
10

40
30
20
10
PS D:\sk> */