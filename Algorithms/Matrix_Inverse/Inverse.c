#include<stdio.h>





int main()
{


int row,col,arr[3][6];

//the original matrix

	for(row=0;row<3;row++)
	{
	
		for(col=0;col<3;col++)
		{
		
			scanf("%d",&arr[row][col]);
		
		
		}

		printf("\n");
	
	
	}

	//identity element on the right

	for(row=0;row<3;row++)
	{
	
		for(col=3;col<6;col++)
		{
		
			if((col-3)==row)
			   arr[row][col]=1;

			else
			   arr[row][col]=0;
		
		
		}
	
	
	
	
	}

	float rat;
	int k=0;
	int l,m,temp,sel;


	for(col=0;col<3;col++)
	{
	
		for(row=0;row<3;row++)
		{
		

		if(arr[col][col]==0)
		{
		
			for(k=col+1;k<3;k++)
			{
			
				if(arr[k][col]!=0)
					sel=k;
			
			
			}

			for(k=0;k<6;k++)
			{
			
				
				
					temp=arr[col][k];
					arr[col][k]=arr[sel][k];
					arr[sel][k]=temp;
				
				
			
			
			
			}
		
		
		
		}

		if(!(row==col))
		{
		
			rat=(float)(arr[row][col])/arr[col][col];	
		
		
		}

		for(k=0;k<6;k++)
		{
		
			arr[row][k]=arr[row][k]-rat*arr[col][k];
		
		
		
		}
		
		
		}
	
	
	
	
	}



	for(k=0,l=3,m=0;k<3,l<6,m<3;m++,l++,k++)
	{
		arr[k][l]=(float)(arr[m][l])/arr[k][k];
	
	
	}

	//printing inverted matrix
	
	for(row=0;row<3;row++)
	{
	
		for(col=3;col<6;col++)
		{
		
			printf("%.3f  ",(float)arr[row][col]);
		
		
		}

		printf("\n");
	
	
	}







}
