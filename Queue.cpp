/*
Name: John Lam
Date: September 12, 2014
Queues
C++
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Node //create node
{
	int number;
	Node* next;
}*front = NULL, *rear = NULL, *pointer = NULL, *nextp = NULL;

void push(int x) // create push function
{
    nextp = new Node;
    nextp->number = x;
    nextp->next = NULL;
    if(front == NULL) //if front is null, point to next pointer
    {
        front = rear = nextp;
        rear->next = NULL; // set rear.next as null
    }
    else
    {
        rear->next = nextp; //set rear.next to next pointer
        rear = nextp; //set rear to next pointer
        rear->next = NULL; //set the rear.next to null
    }
}

int remove()
{
    int x;
    if(front == NULL) //if front is empty, queue is empty
    {
        cout<<"empty queue\n";
    }
    else
    {
        pointer = front; //set pointer to front
        x = pointer->number; //set the x (number to removed) to point to the number
        front = front->next; //set current front to the front's next
        delete(pointer); //delete the pointer
        return(x); // return the value delete
    }
}

int main()
{
    int n,c = 0,x;
    cout<<"Enter the number of values to be pushed into queue\n"; // ask number of values to enter
    cin>>n;
    while (c < n) //while numbers of values does not exceed numbers entered, loop
    {
	cout<<"Enter the value to be entered into queue\n"; //ask user to enter in values
	cin>>x;
        push(x); //addes to list
        c++;
     }
     cout<<"\n\nRemoved Values\n\n"; //removes values
     while(true)
     {
        if (front != NULL)
            cout<<remove()<<endl;
        else
            break;
     }
}