//Code to find (x^y)%m using Fast Exponentiation
#include<stdio.h>
int main()
{
	int base,expo,mod=1000000007,ans=1;
	char choice;
	printf("Note: Base, Exponent and Modulo cannot be greater than 2e9\n");
	printf("Enter Base: ");
	scanf("%d",&base);

	printf("\nEnter Exponent: ");
    scanf("%d",&expo);

	printf("\nDo you want to change Modulo(default is 1e9 + 7) [y/n]: ");
	scanf("%c",&choice);

	if(choice=='y' || 'Y')
        scanf("%d",&mod);

	while(expo!=0)
	{
		if(expo%2 == 0)
		{
			base=(base*base)%mod;
			expo=expo>>1;
						//x^y = (x*x)^(y/2)
		}


		else				//if exponent is odd expo/2 in c won't be mathematically correct
		{
			ans=(ans*base)%mod;
			expo--;
		}
	}

	printf("\nAnswer: %d",ans);

	return 0;
}
