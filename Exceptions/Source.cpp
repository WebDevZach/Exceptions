/*
Zachary Leyes

CIS 1202 201

7/26/2023

Exceptions

*/





#include <iostream>
#include <exception>
#include <cctype>

using namespace std;

class invalidCharacterException : public exception {

public:
	invalidCharacterException() {}
};

class invalidRangeException : public exception {

public:
	invalidRangeException() {}
};





char character(char, int);

int main()
{
	// capital 65 - 90
	// lower 97 - 122


	try
	{

		char ch = '7';
		int value = 25;

		int asciiValue = static_cast<int>(ch);
		


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
	catch (...)
	{
		cout << "generic error" << endl;
	}




	return 0;
}

char character(char start, int offset)
{
	int asciiValue;


	if (islower(start))
	{
		asciiValue = static_cast<int>(start);

		if (asciiValue < 97)
		{
			throw invalidCharacterException();
		}
		if (asciiValue > 122)
		{
			throw invalidCharacterException();
		}
	}
	else
	{
		asciiValue = static_cast<int>(start);

		if (asciiValue < 65)
		{
			throw invalidCharacterException();
		}
		if (asciiValue > 90)
		{
			throw invalidCharacterException();
		}
	}

	int newAsciiValue = start + offset;

	cout << newAsciiValue << endl;

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



	char end;

	end = static_cast<int>(newAsciiValue);


	return end;
}


