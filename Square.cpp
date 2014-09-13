/*
John Lam
September 12, 2014
C++ Tutorial - Calculating Squares
*/

#include <iostream> //import in the io stream library

using namespace std; //make names from std visible without std::

double square (double x){ // square function
	return x*x;
}

void print_square (double x){ // print function
	cout<<"the square of "<<x<<" is "<< square(x) <<"\n";
}

int main (){ //main
	print_square (1.234); //pass 1.234 into print_square f(x) which in thus passes into square f(x), returns answer
}