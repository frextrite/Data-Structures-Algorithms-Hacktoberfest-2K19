// Linear Search //
#include<iostream>
using namespace std;
int main()
{
	int *array;
	int offset,search_value,size;
	
	cout<<"\n\t Enter the size of the array : ";
	cin>>size;
	
	array = new int[size];
	
	for(offset=0;offset<size;offset++)
	{
	   cout<<"\n\t Enter the element  :  ";
	   cin>>array[offset];
	}
	
	cout<<"\n\t Enter the search value : ";
	cin>>search_value;
	
	for(offset=0;offset<size;offset++)
	{
	   if(array[offset]==search_value)break; 	
	}
	
	
	if(offset<size)
	{
		cout<<"\n\t Search value found at position :  "<<offset+1;
	}
	else
	{
		cout<<"\n\t Search value not found ";
	}
}
	
	
