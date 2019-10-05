//Double Circular Linked List

#include<iostream>
#include<cstdio>
using namespace std;

struct node
{
    char data;
    node* next;
    node* prev;
};
void PrintLL(node** header)
{
    puts("\nCurrently the Linked List is as follows...");
    node* temp=(*header);
    cout<<temp->data;
    temp=temp->next;
    while(temp!=(*header))
    {
        cout<<" <--> "<<temp->data;
        temp=temp->next;
    }
    cout<<" <-->\n\n";
    return;

}

void InsertLL(node** header)
{
    cout<<"\nEnter data to be inserted... ";
    node* temp=new node;
    cin>>temp->data;
    temp->next=NULL;
    puts("\nChoose Location :");
    puts("1. Insertion at Front");
    puts("2. Insertion at End");
    puts("3. Insertion after a key element");
    puts("4. Insertion before a key element\n");
    cout<<"Enter your choice...";
    int choice; cin>>choice;
    switch(choice)
    {
        case 1:
            {
                temp->next=(*header)->next;
		        temp->prev=*(header);
                (*header)->next->prev=temp;
		        (*header)->next=temp;
		        if((*header)->prev==(*header))
		            (*header)->prev=temp;
                break;
            }
        case 2:
            {
                temp->prev=(*header)->prev;
		        temp->next=(*header);
                (*header)->prev->next=temp;
                (*header)->prev=temp;
                break;
            }
        case 3:
            {
                node* traverse=(*header)->next;
                cout<<"Enter key element... ";
                char key; cin>>key;
                int flag=0;
                while(traverse!=(*header))
                {
                    if(traverse->data==key)
                    {
                        flag=1;
                        temp->prev=traverse;
                        temp->next=traverse->next;
                        traverse->next->prev=temp;
                        traverse->next=temp;
                        break;
                    }
                    traverse=traverse->next;
                }
                if(!flag)
                    puts("\nEntered key not found.");
                break;
            }
        case 4:
            {
                cout<<"Enter key element... ";
                char key; cin>>key;
                node* traverse=(*header)->next;
                node* prev_traverse=(*header);
                int flag=0;
                while(traverse!=*(header))
                {
                    if(traverse->data==key)
                    {
                        flag=1;
                        temp->next=traverse;
                        temp->prev=prev_traverse;
                        prev_traverse->next=temp;
                        traverse->prev=temp;
                        break;
                    }
                    prev_traverse=traverse;
                    traverse=traverse->next;

                }
                if(!flag)
                    puts("\nEntered key not found");
                break;
            }
        default: puts("\nOops! Wrong Option");
    }
    return;
}
void DeleteLL(node** header)
{
    if((*header)->next==(*header))
    {
        puts("\nLinked List is empty");
        puts("No Deletion can be performed");
        return;
    }
    puts("\nChoose deletion operation :");
    puts("1. Deletion from Front");
    puts("2. Deletion from End");
    puts("3. Deletion of a node with specific key\n");
    cout<<"Enter your choice...";
    int choice; cin>>choice;
    switch(choice)
    {
        case 1:
            {
                node* temp=(*header)->next;
                (*header)->next=temp->next;
                temp->next->prev=(*header);
                cout<<endl<<temp->data<<" deleted from Linked List\n";
                free(temp);
                break;
            }
        case 2:
            {
                node* ToDelete=(*header)->prev;
                node* prev_ToDelete=ToDelete->prev;
                cout<<endl<<ToDelete->data<<" deleted from Linked List\n";
                free(ToDelete);
                prev_ToDelete->next=(*header);
		        (*header)->prev=prev_ToDelete;
                break;
            }
        case 3:
            {

                cout<<"Enter key element... ";
                char key; cin>>key;
                node* traverse=(*header)->next;
                node* prev_traverse=(*header);
                int flag=0;
                while(traverse!=(*header))
                {
                    if(traverse->data==key)
                    {
                        flag=1;
                        prev_traverse->next=traverse->next;
                        traverse->next->prev=prev_traverse;
                        cout<<endl<<traverse->data<<" deleted from Linked List\n";
                        free(traverse);
                        break;
                    }
                    prev_traverse=traverse;
                    traverse=traverse->next;
                }
                if(!flag)
                {
                    puts("Entered key not found.");
                }
                break;
            }
        default: puts("Oops! Wrong Option");

    }
    return;
}

int main()
{
    node* header=new node;
    header->next=header;
    header->data='H';
    header->prev=header;
    puts("######## Welcome to Doubly Circular Linked List ########");
    Repeat:
    PrintLL(&header);
    puts("What do you want to do?");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Exit\n");
    cout<<"Enter your choice... ";
    int choice; cin>>choice;
    switch(choice)
    {
        case 1: InsertLL(&header); break;
        case 2: DeleteLL(&header); break;
        case 3: return 0;
        default: puts("\nSorry! Wrong choice. Please try again");
    }
    goto Repeat;
    return 0;
}
