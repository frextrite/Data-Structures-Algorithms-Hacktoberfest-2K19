#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll prime[n+1];
	for(ll i=0;i<=n;i++)
		prime[i]=1;
	prime[0]=0;
	prime[1]=0;
	for(ll i=2;i<=sqrt(n);i++)
	{
		if(prime[i]==1)
		{
			for(ll j=2;i*j<=n;j++)
				prime[i*j]=0;
		}
	}
	for(ll i=0;i<=n;i++)
		if(prime[i]==1)
			cout<<i<<' ';
		return 0;
}