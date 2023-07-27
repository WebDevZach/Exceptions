/*
Zachary Leyes

CIS 1202 201

7/26/2023

Exceptions 

*/


#include <iostream>

using namespace std;

char character(char, int);

int main()
{
	// capital 65 - 90
	// lower 97 - 122


	try
	{

	


	}
	catch ()
	{

	}


	char ch = 'a';
	int asciiValue = static_cast<int>(ch);
	cout << "ASCII value of " << ch << " is: " << asciiValue << endl;

	ch = 'z';
	asciiValue = static_cast<int>(ch);
	cout << "ASCII value of " << ch << " is: " << asciiValue << endl;



	return 0; 
}

char character(char start, int offset)
{

	int asciiValue = static_cast<int>(start);
	int newAsciiValue = start + offset;



	return;
}
