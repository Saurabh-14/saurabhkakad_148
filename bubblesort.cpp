#include<iostream>
using namespace std;
void bubblesort(int a[],int n)
{
    int temp;
    for(int i =0;i<n-1;i++)
    { 
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int a[20],n;
    cout<<"How many elements to sort";
    cin>>n;
    cout<<"Enter "<<n<<" unsorted elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubblesort(a,n);
    cout<<"Sorted list is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}

//Output

/*PS D:\sk> cd "d:\sk\" ; if ($?) { g++ bubblesort.cpp -o bubblesort } ; if ($?) { .\bubblesort }
How many elements to sort 8
Enter 8 unsorted elements 10 12 50 30 24 52 7 45
Sorted list is
7
10
12
24
30
45
50
52
PS D:\sk>*/ 