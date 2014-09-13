/*
Name: John Lam
Date: September 12, 2014
Stacks
C++
*/

#include <iostream>

using namespace std;

template< class T > //create template to run for generic types

class Stack { //create stack class

private: //contain the private contents of MAX, top and the items of generic types
   int MAX;
   int top;
   T* items;

public:
	Stack(int size){ //create stack
		MAX = size;
		top = -1;
		items = new T[MAX];
	}

	~Stack(){ delete [] items; } // cleans up memory space

	void push(T c){ //push item C into the stack
		if(full()){
			cout << "Stack Full!" << endl; // if full, displays error
			exit(1);
		}

		items[++top] = c; //pushes the item as the new top
	}

	T pop(){
		if(empty()){
			cout << "Stack Empty!" << endl; // if empty, displays error
			exit(1);
		}

		return items[top--]; // removes the top item
	}

	int empty(){  //it is empty when top == -1
		return top == -1; 
	} 

	int full(){  // full when top is equal to max
		return top+1 == MAX; 
	}
};

int main(){

	Stack<char> st(10); //ASCII numbers

        //the letters 'A' - 'J'
	for(int i = 65; i < 75; i++)
		st.push(i);

        //remove all the data
	for(int j = 0; j < 10; j++)
		cout << st.pop() << endl;

	return 0;
}
