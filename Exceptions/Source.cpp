/*
Zachary Leyes

CIS 1202 201

7/26/2023

Exceptions 

*/





#include <iostream>
#include <exception>

using namespace std;

class invalidCharacterException : public exception {

public:
	invalidCharacterException() {
	cout << "yoooo daddy" << endl;
	}
};





char character(char, int);

int main()
{
	// capital 65 - 90
	// lower 97 - 122


	try
	{

	char ch = 'A';

	cout << character(ch, 1);
	


	}
	catch (invalidCharacterException)
	{
		cout << "fiddlesticks" << endl;
	}




	return 0; 
}

char character(char start, int offset)
{
	

	int asciiValue = static_cast<int>(start);

	if (asciiValue < 65)
	{
		throw invalidCharacterException();
	}
	if (asciiValue > 90 && asciiValue < 97)
	{
		throw invalidCharacterException();
	}
	if (asciiValue > 122)
	{
		throw invalidCharacterException();
	}


	int newAsciiValue = start + offset;

	char end;

	end = static_cast<int>(newAsciiValue);


	return end;
}


