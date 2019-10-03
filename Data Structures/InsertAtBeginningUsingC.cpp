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
	node* temp = (node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=head;
	head=temp;
}
void print()
{
	struct node* temp=head;
	printf("List is: \n");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
		printf(" ");
	}
	printf("\n");
}
int main()
{
	head = NULL;
	printf("How many numbers?\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the Number \n");
		scanf("%d",&x);
		insert(x);
		print();
	}
}
