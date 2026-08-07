#include <iostream>
#include <string>
using namespace std;

// Function to read a string from the user
string readString()
{
	// Prompt the user to enter a string
	string str;

	// Read the entire line of input from the user
	cout << "Enter a string: ";
	getline(cin, str);

	// Return the input string
	return str;
}


// Function to convert a string to lowercase
string toLower(const string& str)
{
	// Initialize an empty string to store the result
	string result;
	// Iterate through each character in the input string
	for (char ch : str)
	{
		// Convert the character to lowercase and append it to the result
		result += tolower(ch);
	}
	// Return the result string in lowercase
	return result;
}

// Function to convert a string to uppercase
string toUpper(const string& str)
{
	// Initialize an empty string to store the result
	string result;
	// Iterate through each character in the input string
	for (char ch : str)
	{
		// Convert the character to uppercase and append it to the result
		result += toupper(ch);
	}
	// Return the result string in uppercase
	return result;
}


//main function
int main()
{

	string inputString = readString(); // Read a string from the user

	string upperCaseString = toUpper(inputString); // Convert the string to uppercase

	string lowerCaseString = toLower(inputString); // Convert the string to lowercase

	cout << "the original string is: " << inputString << endl; // Print the original string

	cout << "the uppercase string is: " << upperCaseString << endl; // Print the uppercase string

	cout << "the lowercase string is: " << lowerCaseString << endl; // Print the lowercase string
	
	// Return 0 to indicate successful execution
	return 0;
}
