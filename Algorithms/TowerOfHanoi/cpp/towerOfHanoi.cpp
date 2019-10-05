/*
Recursive solution to the tower of hanoi problem.
Date Created: 05/10/2019
*/
#include <iostream>
#include <stack>
using namespace std;

void init(stack<int> &s, int n);
void print_stack(stack<int> s);
void print_towers();
void solve(stack<int> &, stack<int> &, stack<int> &, int);

// Declare the towers.
stack<int> towers[3];

int main()
{
    
    int n;

    cout<<"Enter the no of stacks: ";
    cin>>n;

    init(towers[2], n);

    cout<<"Solving... "<<endl<<endl; 
    solve(towers[2], towers[0], towers[1], n);
    
    return 0;
}

void init(stack<int> &s, int n)
{
    // Initializes the stack with numbers
    // from 1 to n (both inclusive).
    for (int i = n; i >= 1; i--)
         s.push(i);
}

void print_stack(stack<int> s)
{
    // Function to print a single stack.
    if (s.empty())
    {
        cout<<"Empty stack."<<endl;
        return;
    }
    
    // Since we want to print the stacks in reverse 
    // order we first pop the elements to a temporary(temp)
    // stack & then we use another loop to print it.
    stack<int> temp;    // Create a temporary stack.
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    
    // Print the elements of the temp stack.
    while (!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

void print_towers()
{
    // Function to print all the stacks.
    print_stack(towers[0]);
    print_stack(towers[1]);
    print_stack(towers[2]);
    cout<<endl;
    cout<<"----------------------"<<endl;

}

void solve(stack<int> &initial, stack<int> &final, stack<int> &auxiliary, int n)
{
    // Function to solve the problem.
    if (n == 1)
    {
        final.push(initial.top());
        initial.pop();

        print_towers();
        return;
    }

    print_towers();
    
    solve(initial, auxiliary, final, n - 1);
    solve(initial, final, auxiliary, 1);
    solve(auxiliary, final, initial, n - 1);
}
