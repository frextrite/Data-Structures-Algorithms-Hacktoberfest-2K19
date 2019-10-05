#include<iostream>
#include<string>

using namespace std;

template <typename T>
class Node {
public:
	Node* next;
	string key;
	T value;

	Node(string key, T value) {
		this->key = key;
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

	void appendNode(string key, T value) {
		//declare the new node
		Node<T>* newNode = new Node<T>(key, value);

		//inserting the first node in the list
		if (head == NULL) {
			head = new Node<T>(key, value);
			return;
		}

		//appending new Node after the last node in the list
		Node<T>* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new Node<T>(key, value);
	}

	void print() {
		Node<T>* ptr = head;
		while (ptr != NULL) {
			cout << " ==>> (" << ptr->key << ", " << ptr->value << ")";
			ptr = ptr->next;
		}
	}

	T getValueAtKey(string key) {
		Node<T>* ptr = head;
		while (ptr != NULL) {
			//the actual node with the entered key
			if (key.compare(ptr->key) == 0) {
				return ptr->value;
			}
			ptr = ptr->next;
		}
	}

	bool containsKey(string key) {
		Node<T>* ptr = head;
		while (ptr != NULL) {
			//the actual node with the entered key
			if (key.compare(ptr->key) == 0) {
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}
};


template <typename T>
class HashTable {
	int tableSize;
	LinkedList<T>* itemsArray;

	//a simple hashing function that returns an index of the key's value in the table
	int hashFunction(string key) {
		long long hashSum = 0;
		for (long long i = 0; i < key.size(); i++) {
			//note : 100151 just a simple first prime number that is > 10^5
			hashSum += ((i + 1) * key[i]) % 100151;
			hashSum = hashSum % 100151;
		}
		return hashSum % tableSize;
	}
	bool containsKey(string key) {
		int index = hashFunction(key);
		return itemsArray[index].containsKey(key);
	}
public:
	HashTable(int tableSize) {
		this->tableSize = tableSize;
		itemsArray = new LinkedList<T>[tableSize];
	}
	
	void insert(string key, T value) {
		int index = hashFunction(key);
		//insert if the key was not found in the table before
		if(!containsKey(key))
			itemsArray[index].appendNode(key, value);
	}
	
	//returns NULL if the value was not in the whole table
	T getValue(string key) {
		int index = hashFunction(key);

		if(itemsArray[index].containsKey(key))
			return itemsArray[index].getValueAtKey(key);
		return NULL;
	}
	
	void printTable() {
		for (int i = 0; i < tableSize; i++) {
			cout << "At index " << i << " : ";
			itemsArray[i].print();
			cout << "\n";
		}
	}
};


int main() {
	int tableSize = 10;
	HashTable<int> myAgeTable(tableSize);

	myAgeTable.insert("John",18);
	myAgeTable.insert("Thomas", 21);
	myAgeTable.insert("Frank", 39);
	myAgeTable.insert("Ivan", 27);
	myAgeTable.insert("Julia", 29);
	myAgeTable.insert("Scarllet", 40);
	myAgeTable.insert("Sara", 19);

	//wouldn't be inseted since the key was there before
	myAgeTable.insert("Scarllet", 30);

	myAgeTable.printTable();
	
	return 0;
}
