#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int item;
void insert_beginning(void);
void insert_end(void);
void insert_location();
void insert_after_value();
void delete_by_location();
void delete_by_item();
void display(void);
struct node
{
	int data;
	struct node* next;
};
struct node *start;
struct node*tail=NULL;
void main()
{
	int choice;
	while(1)
	{
		printf ("\n LINKED LIST: \n 1. INSERT AT THE BEGINNING\n 2. INSERT AT THE END\n 3. INSERT AT A GIVEN LOCATION\n 4. INSERT AFTER A GIVEN VALUE\n 5. DELETE BY LOCATION\n 6. DELETE BY VALUE\n 7. DISPLAY\n 8. EXIT\n\n");
		printf ("\nENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_beginning();
				break;
			case 2:insert_end();
				break;
			case 3:insert_location();
				break;
			case 4:insert_after_value();
				break;
			case 5:delete_by_location();
				break;
			case 6:delete_by_item();
				break;
			case 7:display();
				break;
			case 8:exit(0);
				break;
			default: printf("\n YOU HAVE ENTERED A WRONG CHOICE\n");
		}
	}
}
void insert_beginning()
{
	struct node *p= start, *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER ITEM:\n");
	scanf("%d",&item);
	temp->data= item;
	temp->next= start;
	start=temp;
}
void insert_end()
{
	struct node *p= start, *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER ITEM:\n");
	scanf("%d",&item);
	temp->data=item;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	temp->next=NULL;
}
void insert_location()
{
	struct node *p=start, *temp;
	int loc,i;
	printf("\nENTER LOCATION\n ");
	scanf("%d",&loc);
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER ITEM:\n");
	scanf("%d",&item);
	temp->data= item;
	if (loc==1)
	{
		temp->next=p;
		start=temp;
	}
	else
	{
	
		for(i=1;i<loc-1;i++)
		{
			p=p->next;
		}
		struct node *location=p->next;
		p->next=temp;
		temp->next=location;
	}
	
}
void insert_after_value()
{
	int value;
	struct node *p=start, *temp;
	printf("\nENTER DATA OF A NODE AFTER WHICH YOU WISH TO SEE ITEM:\n");
	scanf("%d",&value);
	while(p!=NULL)
	{
		if(p->data==value)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("\n ENTER ITEM:\n");
			scanf("%d",&item);
			temp->data= item;
			temp->next=p->next;
			p->next=temp;
			break;
		}
		p=p->next;
	}
}
void delete_by_location()
{
	struct node *p=start,*old=start,*temp;
	int loc,i;
	printf("\nENTER LOCATION:\n");
	scanf("%d",&loc);
	for(i=1;i<loc;i++)
	{
		p=p->next;
	}
	
	
	if (p==start)
	{
		start=start->next;
		free(p);
	}
	else if (p->next==NULL)
	{
		for(i=1;i<loc-1;i++)
		{
			old=old->next;
		}
		old->next=NULL;
		free (p);
	}
	
	else
	{
		for(i=1;i<loc-1;i++)
		{
			old=old->next;
		}
		old->next=p->next;
		free (p);
	}
}
void delete_by_item()
{
	int value;
	struct node *p=start,*old=start,*temp;
	printf("\nENTER DATA OF A NODE WHICH YOU WISH TO DELETE:\n");
	scanf("%d",&value);
	while(p->data!=value)
	{
		p=p->next;
	}
	
	if (p==start)
	{
		start=start->next;
		free (p);
	}
	else if (p->next==NULL)
	{
		while(old->next->data!=value)
		{
			old=old->next;
		}
		old->next=NULL;
		free (p);
	}
	
	else
	{
		while(old->next->data!=value)
		{
			old=old->next;
		}
		old->next=p->next;
		free (p);
	}
}
void display()
{
	struct node* p= start;
	printf("\n YOUR LINKED LIST LOOKS LIKE :\n\n");
	printf("\n|_START");
	while(p!=NULL)
	{
		printf(" |_%d_|_|->",p->data);
		p=p->next;
	}
	printf("[NULL]\n");
}

