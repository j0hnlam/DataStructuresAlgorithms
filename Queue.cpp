/*
Name: John Lam
Date: September 12, 2014
Queues
C++
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Node 
{
	int number;
	Node* next;
}*front = NULL, *rear = NULL, *pointer = NULL, *nextp = NULL;

void push(int x)
{
    nextp = new Node;
    nextp->number = x;
    nextp->next = NULL;
    if(front == NULL)
    {
        front = rear = nextp;
        rear->next = NULL;
    }
    else
    {
        rear->next = nextp;
        rear = nextp;
        rear->next = NULL;
    }
}

int remove()
{
    int x;
    if(front == NULL)
    {
        cout<<"empty queue\n";
    }
    else
    {
        pointer = front;
        x = pointer->number;
        front = front->next;
        delete(pointer);
        return(x);
    }
}

int main()
{
    int n,c = 0,x;
    cout<<"Enter the number of values to be pushed into queue\n";
    cin>>n;
    while (c < n)
    {
	cout<<"Enter the value to be entered into queue\n";
	cin>>x;
        push(x);
        c++;
     }
     cout<<"\n\nRemoved Values\n\n";
     while(true)
     {
        if (front != NULL)
            cout<<remove()<<endl;
        else
            break;
     }
}