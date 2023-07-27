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

class invalidRangeException : public exception {

public:
	invalidRangeException() {
		cout << "yoooo mama" << endl;
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
	int value = -1;

	int asciiValue = static_cast<int>(ch);
	cout << asciiValue << endl;


	cout << character(ch, value);
	


	}
	catch (invalidCharacterException)
	{
		cout << "fiddlesticks" << endl;
	}
	catch (invalidRangeException)
	{
		cout << "tatar sauce" << endl;
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

	if (newAsciiValue < 65)
	{
		throw invalidRangeException();
	}
	if (newAsciiValue > 90 && asciiValue < 97)
	{
		throw invalidRangeException();
	}
	if (newAsciiValue > 122)
	{
		throw invalidRangeException();
	}



	cout << newAsciiValue << endl;


	char end;

	end = static_cast<int>(newAsciiValue);


	return end;
}


