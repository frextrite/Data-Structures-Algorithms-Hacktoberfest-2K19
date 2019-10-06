#include <iostream>
using namespace std;
struct node{
    node *next, *back;
    int val;
    node(){
        next = nullptr;
        back = nullptr;
    }
    node(int x){
        next = nullptr;
        back = nullptr;
        val = x;
    }
    void addNode(node *newNode){
        next = newNode;
        next->back = this;
    }
    void addVal(int newVal){
        val = newVal;
    }
    void addBack(node *newNode){
        back = newNode;
    }
};

void printDLL(node *myNode, bool isFront){
    node *n = myNode;
    if(isFront)
        while(n->next != nullptr){
            cout << n->val << " -> ";
            n = n->next;
        }
    else
        while(n->back != nullptr){
            cout << n->val << " -> ";
            n = n->back;
        }
    cout << n->val << endl;
}

int main(){
    node *head = new node(), *temp = head;
    for(int x = 1; x <= 20; x++){
        node *n = new node(x);
        temp->addNode(n);
        temp = temp->next;
    }
    cout << "Front to back:" << endl;
    printDLL(head, true);
    cout << "Back to front:" << endl;
    printDLL(temp, false);
    return 0;
}