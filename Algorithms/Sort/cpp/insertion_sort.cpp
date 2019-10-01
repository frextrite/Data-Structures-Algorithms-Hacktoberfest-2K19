#include<iostream>
using namespace std;

void insert(int arr[], int n)
{
for(int i=1;i<n;i++)
{
   int key=arr[i];
   
   int j=i-1;
   
   while(j>=0&&arr[j]>key)
   {
       arr[j+1]=arr[j];
       j=j-1;
   }
   arr[j+1]=key;
}
}

int main()
{
    int n;
    cin>>n;
    
    int a[n];
    
    for(int j=0;j<n;j++)
    cin>>a[j];
    
    insert(a,n);
    
    for(int j=0;j<n;j++)
    cout<<a[j]<<" ";
    
    cout<<endl;
}
