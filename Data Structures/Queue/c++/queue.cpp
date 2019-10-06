/* 
implementation of queue using link list
*/
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
void enqueue(node** z,int x) // insert function
{
    
    if(*z==NULL)
    {
        node* temp = new node();
        temp->data=x;
        temp->next=NULL;
        *z=temp;
        return;
    }
    node* temp = *z;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* temp2=new node();
    temp2->data=x;
    temp2->next=NULL;
    temp->next=temp2;
}
void dequeue(node** z) //deletion function
{
    if((*z)==NULL)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    node* temp=*z;
    (*z)=(*z)->next;
    cout<<"dequeued value is "<<temp->data<<endl;
    free(temp);
}
void print_queue(node** z)// print function 
{
    if ((*z)==NULL)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    node* temp = *z;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* z = NULL;
        enqueue(&z,11);
        enqueue(&z,10);
        enqueue(&z,13);
        print_queue(&z);
        dequeue(&z);S
        print_queue(&z);
    
    return 0;
}
