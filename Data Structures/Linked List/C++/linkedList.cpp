#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
} *head, *tail;

void insert(int val)
{
	if(tail == NULL)
	{
		Node *head = new Node;
		Node *tail = new Node;
		head->data = tail->data = val;
		head->next = tail->next = NULL;
	}
	else
	{
		Node *temp = new Node;
		temp->data = val;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

void delete()
{
	if(head == NULL)
		return;
	
	if(head == tail)
	{
		head = tail = NULL;
		return;
	}

	Node *temp = head;
	while(temp->next != tail)
		temp = temp->next;
	tail = temp;
	temp = temp->next;
	free(temp);
}

void print()
{
	if(head == NULL)
	{
		cout << "Linked List is empty !!\n";
		return;
	}
	Node *temp = head;
	while(temp != NULL)
	{
		cout << head->data << " - ";
		temp = temp->next;
	}
	cout << "\n";
}


int main()
{
	insert(2);
	print();

	insert(3);
	print();

	delete();
	print();

	return 0;
}
