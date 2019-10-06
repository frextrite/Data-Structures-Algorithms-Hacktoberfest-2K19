#include<iostream>

long long int gcd(long long int a,long long int b)
{
	if (a==b)
		return a;
	if (a==0)
		return b;
	if (b==0)
		return a;
	if (~a & 1)
	{
		if(b&1)
			return gcd(a >> 1, b);
		else
			return gcd(a >> 1,b >> 1) << 1;
	}

	if(~b & 1)
		return gcd (a,b >> 1);
	if(a > b)
		return gcd((a-b) >> 1, b);

	return gcd((b-a) >> 1, a);
}

long long int main()
{
	long long int a,b;
	cout<<"Enter the first number"<<endl;
	cin>>a;
	cout<<"Enter the second number"<<endl;
	cin>>b;
	long long int ans=gcd(a,b);
	cout<<"The gcd of the two numbers entered is = "<<ans<<endl;
}