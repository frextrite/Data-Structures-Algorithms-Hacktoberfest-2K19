/*
A C++ Program to Implement Singly Linked List
*/ 
#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

// decalare global variable for head
Node* head = NULL;

// A function to add a new node at the last
void insertNode(int data) {
    if (head == NULL) {
    head = new Node();
    head->data = data;
    head->next = NULL;
    return;
  }
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new Node();
  temp->next->data = data;
  temp->next->next = NULL;
}

// delete node by the position(1 index based)
void deleteNode(int pos) {
  Node* temp = head;
  int i=1;
  if (temp != NULL && pos == 1) {
    head = head->next;
    free(temp);
    return;
  }
  Node* prev;
  while (temp != NULL && i != pos) {
    prev = temp;
    temp = temp->next;
    i++;
  }

  // position not found
  if (temp == NULL) {
    return;
  }

  // unlink that node from linkedlist
  prev->next = temp->next; 

  free(temp);

  return;
}

void printList() {
  Node* temp = head;
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

int main() {
  // Enter nodes to insert

  insertNode(1);
  insertNode(2);
  insertNode(3);
  insertNode(4);

  // Print the linked list
  printList();

  // delete the node at 1st position
  cout<<"After deleteing 1st node"<<endl;
  deleteNode(1);
  printList();

  // delete the node at 2ne position
  cout<<"After deleteing 2nd node"<<endl;
  deleteNode(2);
  printList();

  return 0;
}