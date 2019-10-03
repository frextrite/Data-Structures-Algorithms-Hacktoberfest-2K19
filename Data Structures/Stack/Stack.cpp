#include<iostream>
#include<string>
#include<new>
#define SIZE 10

using namespace std;

void print_vector(int vec[SIZE]){

    int i;
    cout << "\n";
    for(i = 0; i < SIZE; i++){
        cout << vec[i] << " - ";
    }
}

void stack_push(int stac[SIZE],int value, int *top){

    if(*top == SIZE - 1){
        cout << "Stack is full!";
    }   else{
        *top = *top + 1;
        stac[*top] = value;

        }

}

void stack_pop(int stac[SIZE], int *top){

    if(*top == - 1){
        cout << "Stack is empty!";
    }   else{
        cout << "Value Removed: " << stac[*top];
        stac[*top] = 0;
        *top = *top -1;
        }
}

int main(){

    int stac[SIZE]={0,0,0,0,0,0,0,0,0,0};
    int top = -1;

        print_vector(stac);

        stack_push(stac,5, &top);

        print_vector(stac);

        stack_push(stac,7, &top);

        print_vector(stac);

        stack_pop(stac, &top);

        print_vector(stac);

    cout << "\n";

    return 0;
}
