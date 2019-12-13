//Code to a^b using Binary Exponentiation with O(log n)
#include<bits/stdc++.h>
using namespace std;
int binpow(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    int res = binpow(a,b/2);
    if(b%2==0)
    {
        return res*res;
    }
    else
    {
        return res*res*a;           //if exponent is odd 
    }
}
using namespace std;
int main()
{
    int base,expo
    cout<<"Note: Base, Exponent and Modulo cannot be greater than 2e9\n"<<endl;
    cout<<"Enter Base: ";
    cin>>base;

    cout<<"\nEnter Exponent: ";
    cin>>expo;

    cout<<"Result (base^expo): "<<binpow(base,expo);     // result = a^b
}