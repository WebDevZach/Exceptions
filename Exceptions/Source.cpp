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

//Error for invalid input for the character function
class invalidCharacterException : public exception {

public:
	invalidCharacterException() {}
};

//Error for if the offset makes the new value out of bounds 
class invalidRangeException : public exception {

public:
	invalidRangeException() {}
};


char character(char, int);


int main()
{
	int selection = 0;

	//Looping menu
	while (selection != 2)
	{

		try
		{
			char ch;
			int offsetValue;

			//Asks user for a letter
			cout << "Enter a letter: ";
			cin >> ch;

			//Asks user for an offset value
			cout << "Enter an offset value: ";
			cin >> offsetValue;

			//Displays user the new letter 
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

		//Asks user if they want to enter another letter
		cout << "\nPress 2 to exit or 1 to enter another letter" << endl;
		cin >> selection;
	}

	return 0;
}

//Calculates the letter based of the starting letter and offset
char character(char start, int offset)
{
	int asciiValue;
	int newAsciiValue;
	char end;

	//Checks if the character is lower or upper case
	if (islower(start))
	{
		//Finds ascii value
		asciiValue = static_cast<int>(start);

		//Throws error if the starting letter is not between the ascii values for letters a-z
		if (asciiValue < 97)
		{
			throw invalidCharacterException();
		}
		if (asciiValue > 122)
		{
			throw invalidCharacterException();
		}

		//Adds offset
		newAsciiValue = start + offset;

		//Throws error if the offset makes the new value out of bounds of the alphabet
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
		//Finds ascii value
		asciiValue = static_cast<int>(start);

		//Throws error if the starting is letter is not between the ascii values for letter A-Z
		if (asciiValue < 65)
		{
			throw invalidCharacterException();
		}
		if (asciiValue > 90)
		{
			throw invalidCharacterException();
		}

		//Adds offset
		newAsciiValue = start + offset;

		//Throws error if the offset make the new value out of bounds of the alphabet
		if (newAsciiValue < 65)
		{
			throw invalidCharacterException();
		}
		if (newAsciiValue > 90)
		{
			throw invalidCharacterException();
		}
	}
	
	//Turns ascii value back into a character letter
	end = static_cast<int>(newAsciiValue);

	//Returns character
	return end;
}


