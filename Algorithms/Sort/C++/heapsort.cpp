#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>

#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define loop(i,j,n) for(ll i=j;i<n;i++) 

using namespace std;

void heapify(int a[],int i,int n)
{

	int l=2*i+1;
	int r=2*i+2;

	int lar=i;

	if(l<n && a[l]>a[lar])
	{
		lar=l;
	}

	if(r<n && a[r]>a[lar])
	{
		lar=r;
	}

	if(lar!=i) 
		{swap(a[i],a[lar]);

			heapify(a,lar,n);
		}

	}

	void build(int a[],int n)
	{	
		for(int i=n/2-1;i>=0;i--)
		{
			heapify(a,i,n);
		}	
		for(int j=n-1;j>=0;j--)
		{	

			swap(a[0],a[j]);

			heapify(a,0,n);
		}

	loop(i,0,n) cout<<a[i]<<endl;

	}


	int main()
	{

		int n=0;
		cin>>n;

		int *arr = new int(n);

		loop(i,0,n) cin>>arr[i];

		build(arr,n);

		return 0;

	}