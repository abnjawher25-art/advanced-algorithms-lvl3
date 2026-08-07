#include <iostream>
#include<string>
using namespace std;

// Function to read a character from the user
char readChar()
{
	char ch;

	cout << "Enter a character: ";
	cin >> ch;

	return ch;
}

// Function to invert the case of a character
char invertCase(char ch)
{
	return (isupper(ch) ? tolower(ch) : toupper(ch));
}

// Main function
int main()
{
	// Read a character from the user
	char ch = readChar();

	// Invert the case of the character
	char invertedCh = invertCase(ch);

	// Display the result
	printf("The inverted case of '%c' is '%c'\n", ch, invertedCh);

	//return 0 to indicate successful execution
    return 0;
}

