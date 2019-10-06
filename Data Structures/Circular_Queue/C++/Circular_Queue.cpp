#include <iostream>
using namespace std;

int Cir_queue[5];
int front = -1, rear = -1, n=5;

/* function to insert a element to the queue*/
void insert_cir_queue(int val) {
   if ((front == 0 && rear == n-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   Cir_queue[rear] = val ;
}
/*Function to delete the element from the queue*/
void delete_cir_queue() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<Cir_queue[front]<<endl;
   
   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}
/*Function to display the queue*/
void display_cir_queue() {
   int f = front, r = rear;
   if (front == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (f <= r) {
      while (f <= r){
         cout<<Cir_queue[f]<<" ";
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<Cir_queue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<Cir_queue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}
int main() {
   
   int number, val;
do {
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   cout<<"Enter choice : ";
   cin>>number;
   switch(number) {
      case 1: 
         cout<<"Input for insertion: ";
         cin>>val;
         insert_cir_queue(val);
         break;
         
      case 2: 
         delete_cir_queue();
         break;
         
      case 3: 
         display_cir_queue();
         break;
         
      case 4: 
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
   }
} while(number != 4);
   return 0;
}
