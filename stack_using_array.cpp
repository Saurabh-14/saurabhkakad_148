 #include <iostream>
 using namespace std;

 const int MAX = 5;

 class Stack
 {
    private:
    int a[MAX];
    int top;

    public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        top++;
        a[top]=x;
    }

    int pop(void)
    {
        int x = a[top];
        top--;
        return x;     
    }

    int peek(void)
    {
        return a[top];
    }
    int full(void)
    {
        if(top == MAX - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    int empty(void)
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        } 
    }

    void display(void)
    {
        for(int i = top; i>=0; i--)
        {
            cout<< endl <<a[i];
        }
    }
 };

 int main()
 {
    int x;
    Stack s;

    if(!s.full()) s.push(10);
    if(!s.full()) s.push(44);
    if(!s.full()) s.push(54);
    if(!s.full()) s.push(76);
    if(!s.full()) s.push(88);

    cout << "Stack elements:";
    s.display();

    if (!s.empty())
    {
        x = s.pop();
        cout << endl << "Removed:" <<
        x;
    }
    cout <<endl <<"Stack after pop:";
    s.display();
    
    if(!s.empty())
    {

    x = s.peek();
    cout << endl << "Top element is:" <<x;
    }
    return 0;

 }



//output

/*PS D:\sk> 

        > cd "d:\sk\" ; if ($?) { g++ stack_using_array.cpp -o stack_using_array } ; if ($?) { .\stack_using_array }
Stack elements:
88
76
54
44
10
Removed:88
Stack after pop:
76
54
44
10
Top element is:76
PS D:\sk> */