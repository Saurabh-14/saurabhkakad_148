#include <iostream>
#include<cmath>
using namespace std;
class Stack {
private:
int arr[100];
int top;
public:
Stack() {
top = -1;
}
void push(int val) {
arr[++top] = val;
}
int pop() {
int p = arr[top--];
return p;
}
};
int evaluate(char x,int op1,int op2)
{
if(x=='+') return(op1+op2);
if(x=='-') return(op1-op2);
if(x=='*') return(op1*op2);
if(x=='/') return(op1/op2);
if(x=='%') return(op1%op2);
if(x=='$') return(pow(op1,op2));
}
int main(void)
{
Stack s;
char x;
int op1,op2,val;
cout<<"\n Enter postfix Expression :";
while((x= getchar()) != '\n')
{
if(isdigit(x))
{
s.push(x-48);
}
else
{
op2=s.pop();
op1=s.pop();
val=evaluate(x,op1,op2);
s.push(val);
}
}
val=s.pop();
cout<<"\n Answer="<<val;
return 0;
}

//output:

/*> cd "d:\sk\" ; if ($?) { g++ postfix_expression_final.cpp -o postfix_expression_final } ; if ($?) { .\postfix_expression_final }

 Enter postfix Expression :86253+-382/+*2$3+

 Answer=1766
PS D:\sk> \*/