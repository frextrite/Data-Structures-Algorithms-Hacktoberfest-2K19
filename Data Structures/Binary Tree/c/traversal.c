#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct btnode
{

	int data;
	struct btnode*left;
    struct btnode*right;

};

struct btnode*root=NULL,*parent,*temp;


#define count 10

void insertion();
void inorder(struct btnode*);
void preorder(struct btnode*);
void postorder(struct btnode*);



int main()
{

	int ch;


	while(1)
	{

		printf(" CHOOSE FROM THE MENU\n 1.insertion \n 2.inorder \n 3.preorder \n 4.postorder \n  5.exit\n");

		scanf("%d",&ch);


	  switch(ch)
	  {

	 		case 1: insertion();
			  		break;

			case 2: inorder(root);
			        cout<<endl;
			        break;

			case 3: preorder(root);
			        cout<<endl;
			        break;

			case 4: postorder(root); 
			        cout<<endl;
			        break;

			case 5: exit(0);


	  }

	}






	return 0;
}



void insertion()
{

	int ch ;
	ch=1;

	int countx=0;

	parent=root;

	while(ch==1)
	{

		temp = (struct btnode*)malloc(sizeof(struct btnode));

		printf("enter the value of data ");
		scanf("%d",&temp->data);

		countx++;

		temp->right=NULL;
		temp->left=NULL;

		if(root==NULL)
		{
			root=temp;

		}

		else

		{
				int county=0;
			struct  btnode*curr;

			 curr=root;

		    	while(curr)
		    	{


		    		parent=curr;


						if((countx%2)==0)

		                 {
		                 	curr=curr->left;


						 }

		                 else
		                 {
		                 	curr=curr->right;
						 }


		      }

		      if((countx%2)==0)
	          {
	          	  parent->left=temp;

			  }
			  else
			  {

			  	  parent->right=temp;

			  }

		}

	  printf(" want to enter more(0/1)  ");
	  scanf("%d",&ch);

	}


}



void inorder(struct btnode *root)
{

    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
    
}

void preorder(struct btnode *root)
{

    if (root == NULL)
        return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
    
}
void postorder(struct btnode *root)
{

    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    
}


