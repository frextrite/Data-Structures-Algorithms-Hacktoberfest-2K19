#include <stdio.h> 
#include <stdlib.h> 
  
struct node { 
    int data; 
    struct node* next; 
};

int node_size = sizeof(struct node);
  
// This function prints contents of linked list starting from 
// the given node 
void printList(struct node* n){ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->next; 
    } 
}
  
int main(){ 
    struct node* head = NULL; 
    struct node* second = NULL; 
    struct node* third = NULL; 
  
    // allocate 3 nodes
    head = (struct node*) malloc(node_size); 
    second = (struct node*) malloc(node_size); 
    third = (struct node*) malloc(node_size); 
  
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with second 
  
    second->data = 2; // assign data to second node 
    second->next = third; // Link second node with third 
  
    third->data = 3; // assign data to third node 
    third->next = NULL; // Null to End Current List
  
    printList(head); 
  
    return 0; 
}