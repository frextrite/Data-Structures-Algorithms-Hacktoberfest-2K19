#include<iostream>
#include<conio.h>
using namespace std;
int d;
struct btnode
{
	int *key;
	btnode **child;
};
void print(btnode* t)
{
	if(t==NULL) return;
	int i;
	for(i=0;i<2*d;i++)
	{
		print(t->child[i]);
		if(t->key[i]!=-1)
		cout<<t->key[i]<<" ";
	}
    print(t->child[2*d]);
}
bool check_leaf(btnode* T)
{
	int flag=0;
	for(int i=0;i<2*d+1;i++)
	if(T->child[i]!=NULL)
	flag=1;
	if(flag==0)
	return (1);
	else
	return (0);
}
void add_to_node(btnode* old_node,int k,btnode* &new_node,int pos)
{
	int i,j;
	for(i=0;i<2*d&&old_node->key[i]!=-1;i++);
	for(j=i-1;j>=pos&&old_node->key[j]>k;j--)
	{
		old_node->key[j+1]=old_node->key[j];
		old_node->child[j+2]=old_node->child[j+1];
	}
	old_node->key[pos]=k;
	old_node->child[pos+1]=new_node;
}
void create_newnode(btnode* &T)
{
	int i;
	T=new btnode;
	T->key=new int[2*d];
	T->child=new btnode*[2*d+1];
	for(i=0;i<2*d;i++) T->key[i]=-1;
	for(i=0;i<2*d+1;i++) T->child[i]=NULL;
}
void nodesplit(btnode* old_node,btnode* &new_node,int &k,int pos)
{
	btnode* N=NULL;
	create_newnode(N);
	if(pos<=d)
	{
		for(int i=d;i<2*d;i++)
		{
			N->key[i-d]=old_node->key[i];
			N->child[i-d+1]=old_node->child[i+1];
			old_node->key[i]=-1;
			old_node->child[i+1]=NULL;
		}
		N->child[0]=old_node->child[d];
		add_to_node(old_node,k,new_node,pos);
	}
	else
	{
		for(int i=d+1;i<2*d;i++)
		{
			N->key[i-(d+1)]=old_node->key[i];
			N->child[i-d]=old_node->child[i+1];
			old_node->key[i]=-1;
			old_node->child[i+1]=NULL;
		}
		N->child[0]=old_node->child[d+1];
        old_node->child[d+1]=NULL;
		add_to_node(N,k,new_node,pos-(d+1));
	}
	k=old_node->key[d];
	old_node->key[d]=-1;
	new_node=N;
}
int setflag(btnode* T,int &k,btnode* &new_node)
{
	int pos;
	if(T==NULL)
	{
		return (1);
	}
	for(pos=0;pos<2*d&&T->key[pos]!=-1;pos++)
	{
		if(k<T->key[pos]) break;
	}
	if(check_leaf(T))
	{
		if(T->key[2*d-1]==-1)
		{
			add_to_node(T,k,new_node,pos);
			return (0);
		}
		else
		{
			nodesplit(T,new_node,k,pos);
			return (1);
		}
	}
	else
	{
		int flag=setflag(T->child[pos],k,new_node);
		if(flag==1)
		{
			if(T->key[2*d-1]==-1)
			{
				add_to_node(T,k,new_node,pos);
				return (0);
			}
		    else
		    {
			    nodesplit(T,new_node,k,pos);
			    return (1);
		    }
		}
	}
}
btnode* create_root(btnode* T,btnode* new_node,int k)
{
	btnode* root=NULL;
        create_newnode(root);
	    root->key[0]=k;
		root->child[0]=T;
		root->child[1]=new_node;
		return (root);
}
void insert(btnode* &T,int k,btnode* new_node)
{
	btnode* root=NULL;
	int flag=setflag(T,k,new_node);
	if(flag) T=create_root(T,new_node,k);
}
int main()
{
	btnode *root=NULL;
	cout<<"enter d\n";
	cin>>d;
	cout<<"enter elements to be inserted \n";
	int next;
	while(cin>>next)
	{
		if(next==-1) break;
		else insert(root,next,NULL);
	}
	print(root);
	return (0);
}
