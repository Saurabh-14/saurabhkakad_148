#include<iostream>
using namespace std;
int linear_search(int a[],int n,int x)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==x)
        return(i);
    }
    return(-1);
}
int main()
{
    int a[20];
    int n;
    cout<<"How many elements";
    cin>>n;
    cout<<"Enter " << n << " elements";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int x;
    cout<<"Enter element to search";
    cin>>x;
    int loaction = linear_search(a,n,x);
    if (loaction == -1)cout<<"Element not found";
    else
    cout<<"Element found at index "<<loaction;
return(0);
}


//output 

/*PS D:\sk> cd "d:\sk\" ; if ($?) { g++ linear_search.cpp -o linear_search } ; if ($?) { .\linear_search }
How many elements 5
Enter 5 elements 5 4 8 9 3
Enter element to search 9
Element found at index 3
PS D:\sk> */