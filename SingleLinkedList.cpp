/*
Name: John Lam
Date: September 12, 2014
Single Linked List
C++
*/

#include <iostream>

using namespace std;

class Node {//Node class
	int number;
	Node* next;

	public:
		Node () {};
		void setNumber (int aNumber) { number = aNumber; };
		void setNext (Node* aNext) {next = aNext; };
		int Number () { return number; };
		Node* Next () {return next; };  
};

class List { //List Class
    Node *head;
  public:
    List() { head = NULL; };
    void Print();
    void Add(int Number);
    void Delete(int Number);
};

void List::Print() {

    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
    cout << tmp->Number();
    cout << " --> ";
    cout << "NULL" << endl;
    }
    else {
    // Parse and print the list
    do {
        cout << tmp->Number();
        cout << " --> ";
        tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
    }
}


 //Add a node to the linked list
void List::Add(int Number) {

    // Create a new node
    Node* newNode = new Node();
    newNode->setNumber(Number);
    newNode->setNext(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->setNext(newNode);
    }
    else {
    // First node in the list
    head = newNode;
    }
}

//Delete a node from the list
void List::Delete(int Number) {

    // Create a temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
    return;

    // Last node of the list
    if ( tmp->Next() == NULL ) {
    delete tmp;
    head = NULL;
    }
    else {
    // Parse thru the nodes
    Node *prev;
    do {
        if ( tmp->Number() == Number ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

    // Adjust the pointers
    prev->setNext(tmp->Next());

    // Delete the current node
    delete tmp;
    }
}

int main (){

	List list; //create new list

	//Add to list
	list.Add (100);
	list.Print ();
	list.Add(200);
  list.Print();
  list.Add(300);
  list.Print();
  list.Add(400);
  list.Print();
  list.Add(500);
  list.Print();

  //Delete from list
  list.Delete(400);
  list.Print();
  list.Delete(300);
  list.Print();
  list.Delete(200);
  list.Print();
  list.Delete(500);
  list.Print();
  list.Delete(100);
  list.Print();
    
}
