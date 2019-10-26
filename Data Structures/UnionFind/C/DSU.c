#include<iostream>
#include<stdlib.h>
using namespace::std;


int *array; // array representing the parents
int *rank; // array representing the ranks

int get_parent(int index)
{
	int parent;
	// TODO
	if(array[index]==index) return index;
	else
	{
		parent = get_parent(array[index]);
		if(array[index]!=parent)
		{
			rank[array[index]]-=1+rank[index];
		}
		array[index]=parent;
	}
	return parent;
}

void make_DSU(int n)
{
	array = (int*)malloc(n*sizeof(int));
	rank = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;++i)
	{
		array[i]=i;
		rank[i]=0;
	}
}
bool find_connected(int i,int j)
{
	return get_parent(i)==get_parent(j);
}
void quick_union(int i,int j)
{
	if(find_connected(i,j))return; // same set already
	else
	{
		if(get_parent(i) > get_parent(j) || (get_parent(i)==get_parent(j) && i>j) )
		{
			array[get_parent(j)] = get_parent(i);
			rank[get_parent(i)]+=1+rank[get_parent(j)];
		}
		else
		{
			array[get_parent(i)] = get_parent(j);
			rank[get_parent(j)]+=1+rank[get_parent(i)];
		}
	}
	return;
}


int main() // driver to test
{
	make_DSU(5);
	cout<<find_connected(2,3)<<endl; //false
	quick_union(2,4); // 2 is child of 4
	quick_union(3,1); // 1 is child of 3
	cout<<find_connected(2,4)<<endl; //true
	cout<<find_connected(2,1)<<endl; //false
	quick_union(0,2); // 0 is child of 4
	cout<<find_connected(0,4)<<endl; //true
	quick_union(1,2); // 1 union 2
	cout<<find_connected(1,4)<<endl; // true
	
}