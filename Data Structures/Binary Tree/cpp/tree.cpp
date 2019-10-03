#include<bits/stdc++.h>
using namespace std;

struct node { 
	int key; 
	struct node *left, *right; 
}; 


node *newNode(int item){ 
	node *temp = new node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 


void inorder(node *root){ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout<<root->key<<" "; 
		inorder(root->right); 
	} 
} 

void preorder(node *root){
		if(root == NULL) return;
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
void postorder(node *root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<" ";
}

struct node* insert(struct node* node, int key) 
{ 
	
	if (node == NULL) return newNode(key); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	return node; 
} 


int main() 
{ 
	
	struct node *root = NULL; 
	root = insert(root, 500); 
	insert(root, 300); 
	insert(root, 200); 
	insert(root, 400); 
	insert(root, 700); 
	insert(root, 600); 
	insert(root, 800); 

	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	postorder(root);
	return 0; 
} 
