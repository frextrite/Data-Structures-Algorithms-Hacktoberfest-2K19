/*
 implementation  of radix sort 
 */
#include<iostream>
using namespace std;
int max( int arr[],int b)  // defining function to find greatest number
{    
    int j=arr[0];
    for( int i=1; i<b; i++)
       if(arr[i]>j)
       j=arr[i];
       return j;
}
void sort( int k[],int b, int z) // sort function to sort the array according to z
{
	    int y[b];int i;
       int 	count[10] = {0}; 
    for (i = 0; i < b; i++) 
        count[ (k[i]/z)%10 ]++;
         for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i=b-1; i>= 0;i--) 
    { 
        y[count[ (k[i]/z)%10 ] - 1] = k[i]; 
        count[ (k[i]/z)%10 ]--; 
    } 
    for (i = 0; i < b; i++) 
        k[i] = y[i]; 
} 
void radixsort(int k[], int n)  //RADIX SORT FUNCTION 
{ 
    int m = max(k, n); 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        sort(k, n, exp);  // call for sort function 
} 	
void print(int k[], int n)  // funtion to print the array 
{ 
    for (int i = 0; i < n; i++) 
        cout << k[i] << " "; 
} 	 

int main()
{
	  int a;
	cout<<"enter length of array\n";
	  cin>>a;
	cout<<"enter the elements \n";
      int k[a];
	for(int i=0;i<a;i++)
	{
	  cin>>k[i];
	}
	radixsort(k,a);
	print(k,a);

	return 0;
}