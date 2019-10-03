#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head;
void insert(int data,int pos)
{
	node* temp = new node();
	temp->data=data;
	temp->next=NULL;
	if(pos==1)
	{
		temp->next=head;
		head=temp;
		return;
	}
	node* temp1 = head;
	for(int i=0;i<pos-2;i++)
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}
void display()
{
	node* temp=head;
	printf("Linked List: \n");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
		printf("\t");
	}
}
int main()
{
	head=NULL;
	insert(3,1);
	insert(5,2);
	insert(1,1);
	insert(2,2);
	display();
	return 0;
}
