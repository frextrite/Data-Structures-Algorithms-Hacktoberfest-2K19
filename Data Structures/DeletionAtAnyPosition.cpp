#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head;
void insert(int data)
{
	node* temp= new node();
	temp->data=data;
	temp->next=head;
	head=temp;
}
void display()
{
	node* temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
		printf(" \n");
	}
}
void delete1(int pos)
{
	node* temp=head;
	int i;
	if(pos==1)
	{
		head=temp->next;
		free(temp);
		return;
	}
	for(i=0;i<pos-2;i++)
	{
		temp=temp->next;
	}
	node* temp1 = temp->next;
	temp->next=temp1->next;
	free(temp1);
}
int main()
{
	head=NULL;
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	display();
	delete1(3);
	printf("\n");
	display();
	delete1(1);
	printf("\n");
	display();
	return 0;
}
