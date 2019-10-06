import java.util.*;
import java.io.*;
class quicksort
{

public static void sort(int[] arr,int first,int last)
{ 		
		int pivot, i,j,temp;
		if(first<last)
		{ pivot=first;
			i=first;
			j=last;
			while(i<j)
			{	while(arr[i]<=arr[pivot]&&i<last)
					i++;
				while(arr[j]>arr[pivot])
					j--;
				if(i<j)
				{ temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}	
			temp=arr[pivot];
			arr[pivot]=arr[j];
			arr[j]=temp;
			sort(arr,first,j-1);
			sort(arr,j+1,last ;
		} 
}
public static void main(String args[])     
	{ System.out.println("Enter the number of elements of array");
 	 Scanner scan = new Scanner(System.in);
	  int q= scan.nextInt();
		int[] arr=new int[q];
	  System.out.println("Enter the elements of array");
		for(int i=0; i<q;i++)
		{ 
		arr[i]=scan.nextInt();
		}
		sort(arr,0,q-1);
	  System.out.println(" elements of array after sorting");
		for(int i=0; i<q;i++)
		{ System.out.println(arr[i]);
		}
	} 
} 