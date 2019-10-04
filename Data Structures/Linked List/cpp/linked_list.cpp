#include<iostream>

using namespace std;

template <typename T>
class Node {
public:
	Node* next;
	T value;

	Node(T value) {
		this->value = value;
		this->next = NULL;
	}
};

template <typename T>
class LinkedList {
	Node<T>* head;
public:
	LinkedList() {
		head = NULL;
	}
	
	void appendNode(T value) {
		//declare the new node
		Node<T>* newNode = new Node<T>(value);

		//inserting the first node in the list
		if (head == NULL) {
			head = new Node<T>(value);
			return;
		}

		//appending new Node after the last node in the list
		Node<T>* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new Node<T>(value);
	}
	
	void print() {
		cout << "Linked List : \n";

		Node<T>* ptr = head;
		while (ptr != NULL) {
			cout << " ==>> " << ptr->value;
			ptr = ptr->next;
		}
		
		cout << "\n";
	}
};

int main() {
	
	LinkedList<int> myList;
	myList.appendNode(1);
	myList.appendNode(3);
	myList.appendNode(5);
	myList.appendNode(7);
	myList.appendNode(9);
	myList.appendNode(11);

	myList.print();
	return 0;
}
