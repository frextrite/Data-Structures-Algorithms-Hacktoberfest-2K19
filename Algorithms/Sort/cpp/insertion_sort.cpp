#include<iostream>
#include<algorithm>
using namespace std;
int main()
 {
   long long int t,n;
   cin>>t;
   
   for(int i=1;i<=t;i++)
   {
     cin>>n;
  
   long long int a[n];
   
    for(int j=0;j<n;j++)
   {
     cin>>a[j];
    }
    reverse(a,a+n);
    
    for(int j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<endl;
   }
 }
