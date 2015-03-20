/*
Name: John Lam
Date: September 12, 2014
Single Linked List
C++
*/

#include <iostream>

using namespace std;

class List {

  private:
    typedef struct node {

      int data;
      node* next;

    }*nodePtr;

    nodePtr head;
    nodePtr current;
    nodePtr tmp;

  public: //function prototypes
    List ();
    void Add (int addNumber);
    void Delete (int deleteNumber);
    void deleteDupe ();
    void Print ();
};

List::List (){
  head = NULL;
  current = NULL;
  tmp = NULL;
}

void List::Add(int addNumber){
  nodePtr n = new node;
  n->next = NULL;
  n->data = addNumber;

  if (head != NULL){
    current = head;
    while (current->next  != NULL){
      current = current->next;
    }
    current->next = n;
  }
  else{
    head = n;
  }
}

void List::Delete(int deleteNumber){
  nodePtr delPtr = NULL;
  tmp = head;
  current = head;

  while (current != NULL && current->data != deleteNumber){
    tmp = current;
    current = current->next; //current advances 1 more than tmp
  }
  if (current == NULL){
    cout << deleteNumber << " was not in the list.\n" << endl;
    delete delPtr;
  }
  else{
    delPtr = current;
    current = current->next;
    tmp->next = current;
    if (delPtr == head){
      head = head->next;
      tmp = NULL;
    }
    delete delPtr;
    cout << "The value of " << deleteNumber << " was deleted.\n" << endl;
  }
}

void List::Print (){
  current = head;
  while (current != NULL){
    cout << current->data << endl;
    current = current->next;
  }
}

void List::deleteDupe (){
  if (head == NULL)
    return;

  current = head;

  while (current != NULL){
      tmp = current;
    while (tmp->next != NULL){
      if (tmp->next->data == current->data){
        tmp->next = tmp->next->next;
      }
      else{
        tmp = tmp->next;
      }
    }
  }
}

int main (){
  List list;

  list.Add (3);
  list.Add (5);
  list.Add (8);
  list.Add (5);
  list.Print ();

  list.deleteDupe();
  list.Print ();

}
