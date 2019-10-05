// implementation of Trie data structure in C
#include <stdio.h>
#include <stdlib.h>      // header files

// define size of character array : 26 for 26 alphabets
#define CHAR_SIZE 26

// Trie declaration
struct Trie
{
	int isLeaf;	// 1 when node is a leaf node
	struct Trie* character[CHAR_SIZE];
};

// Function that returns a new node 
struct Trie* getNewTrieNode()
{
	struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));  // allocate memory to node pointer
	node->isLeaf = 0;           
      int i;
	for(i = 0; i < CHAR_SIZE; i++)
		node->character[i] = NULL;      // no children assigned to node yet

	return node;
}

// Iterative function to insert a string in Trie
void insert(struct Trie *head, char* str)  // head is the root
{
	// begin from the root node
	struct Trie* curr = head;
	while (*str)   // while str is non empty
	{
		// create a new node if path doesn't exist (across the trie)
		if (curr->character[*str - 'a'] == NULL)
			curr->character[*str - 'a'] = getNewTrieNode();

		// go to next node
		curr = curr->character[*str - 'a'];

		// move to next character
		str++;
	}

	// mark current node as leaf
	curr->isLeaf = 1;
}

// Iterative function to search a string in Trie 
// the function returns 1 if the string is found in the Trie, else return 0
int search(struct Trie* head, char* str)
{
	// trie is empty
	if (head == NULL)
		return 0;

	struct Trie* curr = head;
	while (*str)
	{
		// go to next node
		curr = curr->character[*str - 'a'];

		// if string is invalid (reached end of path in Trie)
		if (curr == NULL)
			return 0;

		// move to next character
		str++;
	}

	// if current node is a leaf and we have reached the
	// end of the string, return 1
	return curr->isLeaf;
}

//the function returns 1 if any given node has any children
int haveChildren(struct Trie* curr)
{
	int i;
	for(i = 0; i < CHAR_SIZE; i++)
		if (curr->character[i])   
			return 1;	// child is present and found

	return 0;     // when none of the ifs across the for loop are not satisfied
}

// Recursive function to delete a string in Trie
int deletion(struct Trie **curr, char* str)
{
	// Trie is empty
	if (*curr == NULL)
		return 0;

	// if str is not empty
	if (*str)
	{
		// recur for the node corresponding to next character in the string 
		//and if it returns 1, delete current node (if it is non-leaf)
		 
		if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
			deletion(&((*curr)->character[*str - 'a']), str + 1) &&
			(*curr)->isLeaf == 0)
		{
			if (!haveChildren(*curr))
			{
				free(*curr);    // deallocate memory occupied by curr 
				(*curr) = NULL; // mark current as null to return it to memory pool
				return 1;       
			}
			else {
				return 0;
			}
		}
	}

	// if we reach end of string
	if (*str == '\0' && (*curr)->isLeaf)
	{
		// if current node is a leaf node and dosen't have any children
		if (!haveChildren(*curr))
		{
			free(*curr); // deallocate current node
			(*curr) = NULL;
			return 1; // delete non-leaf parent nodes
		}

		// if current node is a leaf node and have children
		else
		{
			// mark current node as non-leaf node (do not delete it)
			(*curr)->isLeaf = 0;
			return 0;	 
		}
	}

	return 0;
}

// driver function to test above operations 
int main()
{
	struct Trie* head = getNewTrieNode();

	insert(head, "hello");
	printf("%d ", search(head, "hello"));   	// prints 1 since "hello" is present

	insert(head, "helloworld");
	printf("%d ", search(head, "helloworld"));  // prints 1 since "helloworld" is present

	printf("%d ", search(head, "helll"));   	// prints 0 (Not present)

	insert(head, "hell");
	printf("%d ", search(head, "hell"));		// prints 1 since "hell" is present

	insert(head, "h");
	printf("%d \n", search(head, "h")); 		// prints 1 and newline due to \n

	deletion(&head, "hell");
	printf("%d ", search(head, "hello"));   	// prints 1 (hell deleted)
	printf("%d ", search(head, "helloworld"));  // prints 1 as "helloworld" is still present in Trie
	printf("%d \n", search(head, "hell"));  	// prints 0 and newline

	deletion(&head, "h");
	printf("%d ", search(head, "h"));   		// prints 0 (h is deleted)

	deletion(&head, "helloworld");
	printf("%d ", search(head, "helloworld"));  // prints 0

	if (head == NULL)
		printf("Trie empty!!\n");   			// Trie is empty now

	printf("%d ", search(head, "hell"));		// print 0

	return 0;
} 
