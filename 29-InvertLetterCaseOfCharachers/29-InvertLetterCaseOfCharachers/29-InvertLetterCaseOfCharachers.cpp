#include <iostream>
#include<string>
using namespace std;

// Function to read a string from the user
string readString()
{
	string input;

	cout << "Enter a string: ";
	getline(cin, input);

	return input;
}

// Function to invert the case of a character
char invertCase(char ch)
{
	return (isupper(ch) ? tolower(ch) : toupper(ch));
}

// Function to invert the case of a string
string invertStringCase(const string& str)
{
	string invertedStr = str;

	for (char& ch : invertedStr)
	{
		ch = invertCase(ch);
	}


	return invertedStr;
}

// Main function
int main()
{
	// Read a string from the user
	string inputString = readString();

	// Invert the case of the string
	string invertedString = invertStringCase(inputString);

	// Display the result
	cout << "The inverted case of '" << inputString << "' is '" << invertedString << "'" << endl;

	//return 0 to indicate successful execution
	return 0;
}

