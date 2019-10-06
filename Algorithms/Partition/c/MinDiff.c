#include<stdio.h>
#include<stdlib.h>

// A C program using Recursion to solve minimum sum partition problem.  
  
// Function to find the minimum sum
int findMinRec(int arr[], int i, int sumCalculated, int sumTotal) 
{ 
    // If we have reached last element.  Sum of one subset is sumCalculated, sum of other subset is sumTotal-sumCalculated.
    //  Now, we return absolute difference  of two sums. 
    
	if (i==0) 
        return abs((sumTotal-sumCalculated) - sumCalculated); 

    // For every item arr[i], we have two choices 
    // (1) We do not include it first set 
    // (2) We include it in first set 
    // We return minimum of two choices 
    
	int a= findMinRec(arr, i-1, sumCalculated+arr[i-1], sumTotal); 
        int b= findMinRec(arr, i-1, sumCalculated, sumTotal);

	return a<b?a:b;
} 
   
int main() 
{ 
    int n=0; 

	printf("Enter number of elements in the array:\n");
	scanf("%d",&n);

    int arr[n], sumTotal=0; 
  
    //inputing the numbers and getting their sum
	printf("Please enter the numbers:\n");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	sumTotal += arr[i];
	}

	//giving final output of minimum difference between the sum of numbers in any two disjoint and exhaustive subsets.
    printf("\nThe minimum difference between two sets is %d\n\n", findMinRec(arr, n, 0, sumTotal)); 
    return 0; 
}
