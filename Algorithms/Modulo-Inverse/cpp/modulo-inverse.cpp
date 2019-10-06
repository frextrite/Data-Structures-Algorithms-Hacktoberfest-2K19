 #include<iostream>
using namespace std;

int gcd(int a,int b){
	if(b==0)
		return a;

	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int x,y,GCD;
void extended_euclid(int a,int b){
	//Base case
	if(b==0){
		x=1;
		y=0;
		GCD=a;
		return;
	}
	//Recursive case
	extended_euclid(b,a%b);
	int cx=y;
	int cy=x-(a/b)*y;
	x=cx;
	y=cy;
}
int inverseModulo(int a,int m){
	if(gcd(a,m)==1){
		extended_euclid(a,m);
		return (x+m)%m;
	}
	return -1;
}
int main(){

	cout<<inverseModulo(6,7)<<endl;
	return 0;
}