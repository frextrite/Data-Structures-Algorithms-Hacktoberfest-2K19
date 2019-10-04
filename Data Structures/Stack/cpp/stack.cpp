#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class Stack
{
    //Nodal class
    class Node
    {
    public:
        T data;
        Node *next;
        Node()
        {
            next = NULL;
        }
        Node(T val)
        {
            data = val;
        }
    };

    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    //function to push a value into the stack
    void push(T val)
    {
        Node *n = new Node(val);

        //check for memory assignment error
        if (n == NULL)
        {
            cout << "Memory error\n"<< endl;
            exit(0);
        }
        else if(head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        
    }

    //function to return the value at the top of the stack
    T top()
    {
        return head->data;
    }

    //function to pop an element from the top of the stack
    void pop()
    {
        //check for underflow
        if(head==NULL)
        {
            cout<<"Stack underflow\n"<<endl;
            exit(0);
        }
        Node *n = head;
        head = head->next;
        delete(n);
    }
};

int main()
{
    //declaration
    Stack<int> st;

    //push into the stack
    st.push(10);
    st.push(5);

    //pop from the stack
    st.pop();

    //printing the top of the stack
    cout<<st.top()<<endl;

    return 0;
}