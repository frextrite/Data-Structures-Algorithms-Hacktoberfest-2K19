#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    int data;
    struct nodetype *next;
}node;
node* create_node()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    printf("enter data\n");
    scanf("%d",&(ptr->data));
    ptr->next=NULL;
    return ptr;
}
node* create_list(node *tl,int n)
{
    node *ptr; int i;
    ptr=tl;
    for(i=0;i<n;i++)
    {
        ptr->next=create_node();
        ptr=ptr->next;
    }
    ptr->next=tl;
    return ptr;
}
void display_list(node* tail)
{
    if(tail==NULL)
    {
        printf("EMPTY LIST");
    }
    else
    {
        node* curr;
        curr=tail->next;
        printf("Exsisting list:-");
        while(curr!=tail)
        {
            printf("%d  ",curr->data);
            curr=curr->next;
        }
        printf("%d\n",curr->data);
    }
}
node* insert_end(node* tl)
{
    node *newnode,*ptr;
    ptr=tl;
    newnode=create_node();
    newnode->next=ptr->next;
    ptr->next=newnode;
    return newnode;
}
void insert_front(node* tl)
{
    node *newnode,*ptr;
    ptr=tl;
    newnode=create_node();
    newnode->next=ptr->next;
    ptr->next=newnode;
}
void insert_mid(node* tl,int i)
{
    node* ptr;
    node* prev;
    node* newnode;int j;
    ptr=tl->next;
    for(j=1;j<i-1;j++)
    {
        ptr=ptr->next;
    }
    newnode=create_node();
    newnode->next=ptr->next;
    ptr->next=newnode;
}
node* del_end(node* tl)
{
    node *ptr,*newnode;
    ptr=tl->next;
    while(ptr->next!=tl)
    {
        ptr=ptr->next;
    }
    newnode=tl;
    ptr->next=tl->next;
    free(newnode);
    return ptr;
}
void del_front(node* tl)
{
    node *ptr,*newnode;
    ptr=tl->next;
    newnode=ptr;
    ptr=ptr->next;
    tl->next=ptr;
    free(newnode);
}
void del_mid(node* tl,int i)
{
    node* ptr;
    node *prev;
    int j;
    ptr=tl;
    for(j=0;j<i-1;j++)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
    free(ptr);
}
int main()
{
    node* tail;
    int n,c;
    int pos;
    tail=NULL;
    while(c!=0)
    {
        printf("enter 1 to create list\n");
        printf("enter 2 to display the list\n");
        printf("enter 3 to append\n");
        printf("enter 4 to insert at front\n");
        printf("enter 5 to insert at the middle\n");
        printf("enter 6 to delete at end\n");
        printf("enter 7 to delete at front\n");
        printf("enter 8 to delete at the middle\n");
        printf("enter 9 to stop\n");
        printf("enter your choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("enter number of elements of the list\n");
                scanf("%d",&n);
                tail=(node *)malloc(sizeof(node));
                printf("enter data\n");
                scanf("%d",&(tail->data));
                tail->next=tail;
                tail= create_list(tail,n-1);
                break;
            }
            case 2:
            {
                display_list(tail);
                break;
            }
            case 3:
            {
                tail= insert_end(tail);
                n++;
                break;
            }
            case 4:
            {
                insert_front(tail);
                n++;
                break;
            }
            case 5:
            {
                printf("enter your position\n");
                scanf("%d",&pos);
                if(pos>n+1 || pos<=0)
                {
                    printf("invalid position\n");
                    continue;
                }
                else
                {
                    insert_mid(tail,pos);
                    n++;
                }
                break;
            }
            case 6:
            {
                tail= del_end(tail);
                n--;
                break;
            }
            case 7:
            {
                del_front(tail);
                n--;
                break;
            }
            case 8:
            {
                printf("enter your position\n");
                scanf("%d",&pos);
                if(pos>n || pos<=0)
                {
                    printf("invalid position\n");
                    continue;
                }
                else
                {
                    del_mid(tail,pos);
                    n--;
                }
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                printf("wrong choice\n");
                break;
            }
        }
    }
}
