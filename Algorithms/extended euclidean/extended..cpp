#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll gcdExtended(ll a, ll b, ll *x, ll *y)  {

    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}


int main ()
{
    ll g,a,b,x,y;
    cin>>a>>b;
    g = gcdExtended(a,b,&x,&y);
    cout<<"the GCD from "<<a<<" and "<<b<<" is "<<g<<"\n";
    return 0;
}
