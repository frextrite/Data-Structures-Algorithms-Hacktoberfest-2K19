#include <bits/stdc++.h>

using namespace std;


struct Node
{
	int d;
	struct Node* left;
	struct Node* right;
	int bal;
};
typedef struct Node node;

node* newNode(int data)
{
	node* p = new node;
	p->d = data;
	p->left = p->right = NULL;
	p->bal = 0;
	return p;
}

int Height(node* root)
{
	if (root)
	{
		int lHeight = Height(root->left);
		int rHeight = Height(root->right);

		if (lHeight > rHeight)
			return (lHeight + 1);
		else
			return (rHeight + 1);
	}
	else
		return 0;
}

int BalFactor(node* root)
{
	int lHeight = Height(root->left);
	int rHeight = Height(root->right);
	int balfactor = lHeight - rHeight;
	return balfactor;
}

node* rotateLeft(node* root)
{
	node* tempPtr = root->right;
	root->right = tempPtr->left;
	tempPtr->left = root;
	root->bal = BalFactor(root);
	tempPtr->bal = BalFactor(tempPtr);
	return tempPtr;
}

node* rotateRight(node* root)
{
	node* tempPtr = root->left;
	root->left = tempPtr->right;
	tempPtr->right = root;
	tempPtr->bal = BalFactor(tempPtr);
	root->bal = BalFactor(root);
	return tempPtr;
}

node* Insert(node* root, int data)
{
	if (root == NULL)
	{
		root = newNode(data);
	}
	else
	{
		if (data > root->d)
			root->right = Insert(root->right, data);
		else if (data < root->d)
			root->left = Insert(root->left, data);
		else
			cout << "Equal datas are not allowed in AVL trees" << endl;
	}

	root->bal = BalFactor(root);

	if (root->bal > 1 && data < root->left->d)
	{
	    cout<<root->d<<endl;
		root = rotateRight(root);
	}

	if (root->bal < -1 && data > root->right->d)
	{
	    cout<<root->d<<endl;
		root = rotateLeft(root);
	}

	if (root->bal > 1 && data > root->left->d)
	{
		cout<<root->d<<endl;
		root->left = rotateLeft(root->left);
		root = rotateRight(root);
	}

	if (root->bal < -1 && data < root->right->d)
	{
		cout<<root->d<<endl;
		root->right = rotateRight(root->right);
		root = rotateLeft(root);
	}

	return root;
}

void Preorder(node* root)
{
	if (root != NULL)
	{
		cout << root->d << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Inorder(node* root)
{
	if (root != NULL)
	{
	    Inorder(root->left);
		cout << root->d << " ";
		Inorder(root->right);
	}
}

void Postorder(node* root)
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->d << " ";
	}
}

node* Deletenode(node* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	else
	{
		if (data > root->d)
		{
			root->right = Deletenode(root->right, data);
		}
		else if (data < root->d)
		{
			root->left = Deletenode(root->left, data);
		}
		else
		{
			if (root->left == NULL)
			{
				node*p = root->right;
				delete(root);
				return p;
			}
			if (root->right == NULL)
			{
				node* p = root->left;
				delete(root);
				return p;
			}
            
            if(root->right == NULL)
            {
			node* p = root->left;

			if (p != NULL && p->right != NULL)
			{
				p = p->right;
			}
			root->d = p->d;
			root->left = Deletenode(root->left, p->d);
            }
			else
			{
			node* p = root->right;

			if (p != NULL && p->left != NULL)
			{
				p = p->left;
			}

			root->d = p->d;
			root->right = Deletenode(root->right, p->d);
			}
		}

		if (root == NULL)
			return root;

		root->bal = BalFactor(root);

		if (root->bal > 1 && BalFactor(root->left) >= 0)
		{
		    cout<<root->d<<endl;
			root = rotateRight(root);
		}

		if (root->bal < -1 && BalFactor(root->right) <= 0)
		{
		    cout<<root->d<<endl;
			root = rotateLeft(root);
		}

		if (root->bal > 1 && BalFactor(root->left) > 0)
		{
			cout<<root->d<<endl;
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}

		if (root->bal < -1 && BalFactor(root->right) < 0)
		{
			cout<<root->d<<endl;
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	}
	return root;
}

int main()
{
	node* root = NULL;
	int n, y;
	cin>> n;
	char m;
    for(int t = 0; t< n; t++)
    {
        cin>>m >> y;
        if(m == 'i')
        {
           root = Insert(root, y); 
        }
        else if(m == 'd')
        {
            root = Deletenode(root, y);
        }
    }
	

	
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout<< endl;
	Postorder(root);
	cout<<endl;


	return 0;
}
