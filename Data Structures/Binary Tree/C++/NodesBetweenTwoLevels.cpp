//Nodes between two given levels

#include<bits/stdc++.h>
using namespace std;
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
void print(node*root, int low, int high)
{
    if(!root)
        return;
    
    node *marker = new node;
    queue<node*>q;
    //Initial level is 1 
    int level = 1;
    q.push(root);
    //Marker delimits levels
    q.push(marker);
    
    while(!q.empty())
    {
        node *node = q.front();
        q.pop();
        //End of current level reached
        if(node == marker)
        {
            cout<<"\n";
            level++;
            //All nodes which needed to be visited are visited
            if(q.empty() || level > high)
                break;
            q.push(marker);
            
            continue;
        }
        
        if(level >= low)
            cout<<node->key<<" ";
        
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}
   
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // print inoder traversal of the BST 
    inorder(root); 
    print(root, 1, 3);
   
    return 0; 
}
