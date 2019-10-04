#include <iostream>
#include <string>;
using namespace std;

class Node {
public:

	int priority;
	char label, prev_char;
	Node *next, *prev;
	Node(char lbl, int pr) {
		label = lbl;
		priority = pr;
		next = 0;
		prev = 0;
	}

};

class PQueue {

	

	Node *head, *tail;
	void destr_helper(Node *node) {
		if (node) {
			destr_helper(node->next);
			delete node;
		}
	}

public:
	PQueue() {
		head = 0;
		tail = 0;
	}
	~PQueue() {
		destr_helper(head);
	}
	void push(char lbl, int pr) {
		Node *newNode = new Node(lbl, pr);

		if (!head) {
			head = newNode;
			tail = newNode;
			return;
		}

		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		sort_node(head);

	}
	Node *pop() {

		Node *val = tail;
		tail = tail->prev;
		if (tail)
			tail->next = 0;
		else
			head = 0;
		return val;

	}
	Node *peek() {

		return tail;

	}
	Node *search_node(char lbl) {

		Node *temp = tail;
		for (; temp && temp->label != lbl; temp = temp->prev);
		return temp;

	}
	void set_priority(char lbl, int pr) {

		Node *temp = search_node(lbl);
		if (!temp)
			throw "label not found\n";
		temp->priority = pr;
		sort_node(temp);

	}
	int get_priority(char lbl) {

		Node *temp = search_node(lbl);
		if (!temp)
			throw "label not found\n";
		return temp->priority;

	}
	void set_previous(char lbl, char prv) {

		Node *temp = search_node(lbl);
		if (!temp)
			throw "label not found\n";

		temp->prev_char = prv;

	}
	void sort_node(Node *temp) {
		//we don't need to check for a head because so long as we're here, it exists
		//	so long as the current temp has one after it
		//	we're basically pushing nodes with lower priority further down the queue
		//	we don't need a for loop because temp is moving itself along by nature of the algorithm

		while (temp->next && temp->priority < temp->next->priority) {

			//we're cutting out temp from between its prev and next nodes
			temp->next->prev = temp->prev;
			if (temp->prev)						//make sure that temp is not currently the head
				temp->prev->next = temp->next;
			temp->prev = temp->next;
			temp->next = temp->prev->next;
			temp->prev->next = temp;
			if (temp->next)
				temp->next->prev = temp;
			else
				tail = temp;
			if (!temp->prev)
				head = temp;
		}
	}
	void display() {

		//make sure we have a head at least
		if (tail != NULL) {

			//print out head datum
			cout << tail->label << "(" << tail->priority;

			//loop through each element's next and add to string
			Node *current = tail;

			while (current->prev != NULL) {

				current = current->prev;
				cout <<"), " << current->label << "(" << current->priority;

			}


		}

		cout << ")" << endl;

	}

};