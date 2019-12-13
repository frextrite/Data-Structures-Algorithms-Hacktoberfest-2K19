#include<stdio.h>
#include<stdlib.h>
#define max 50
void push();
void pop();
void display();
int menu();
void get_top();
void get_sizeOfStack();
int stack[max], top = 0;

void main()
{
	int ch;

	do 
	{
		ch = menu();
		switch (ch)
		{
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4: get_top();
			break;
		case 5: get_sizeOfStack();
			break;
		case 6: exit(0);
		default: printf("\nEnter a valid choice!!");
		}
	} while (1);
}

int menu()
{
	int ch;
	printf("\nStack");
	printf("\n1.Push\n2.Pop\n3.Display\n4.get_Top5.get_size\n6.Exit");
	printf("\nEnter your Choice:");
	scanf_s("%d", &ch);
	return ch;
}

void push()
{
	if (top == max)
		printf("\nOverflow");
	else
	{
		int element;
		printf("\nEnter Element:");
		scanf_s("%d", &element);
		printf("\nElement(%d) has been pushed at %d", element, top);
		stack[top] = element;
		top++;
	}
}

void pop()
{
	if (top == -1)
		printf("\nUnderflow");
	else
	{
		top--;
		printf("\nELement has been popped out!");
	}
}

void display()
{
	if (top == 0)
		printf("\nStack is Empty!!");
	else
	{
		int i;
		for (i = 0; i < top; i++)
			printf("%d ", stack[i]);
	}
}

void get_top()
{
	if (top == 0)
		printf("\nStack is Empty!!");
	else
	{
		printf("the element stack top: ");
		printf("%d\n", stack[top]);
	}
}
void get_sizeOfStack()
{
	printf("The stack is size: ");
	printf("%d\n", top + 1);
}
