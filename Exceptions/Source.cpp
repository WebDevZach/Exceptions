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
	int selection = 0;

	while (selection != 2)
	{

		try
		{

			char ch;
			int offsetValue;

			cout << "Enter a letter: ";
			cin >> ch;

			cout << "Enter an offset value: ";
			cin >> offsetValue;

			int asciiValue = static_cast<int>(ch);

			cout << "Your new letter: " << character(ch, offsetValue) << endl;
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
		
		cout << "\nPress 2 to exit or 1 to enter another letter" << endl;
			cin >> selection;
	}


	return 0;
}

char character(char start, int offset)
{
	int asciiValue;
	int newAsciiValue;
	char end;


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

		newAsciiValue = start + offset;

		if (newAsciiValue < 97)
		{
			throw invalidRangeException();
		}

		if (newAsciiValue > 122)
		{
			throw invalidRangeException();
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

		newAsciiValue = start + offset;

		if (newAsciiValue < 65)
		{
			throw invalidCharacterException();
		}
		if (newAsciiValue > 90)
		{
			throw invalidCharacterException();
		}
	}

	end = static_cast<int>(newAsciiValue);

	return end;
}


