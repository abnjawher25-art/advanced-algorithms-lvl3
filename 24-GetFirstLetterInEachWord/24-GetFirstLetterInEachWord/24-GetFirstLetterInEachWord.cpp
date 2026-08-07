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

// Function to get the first letter of each word in a string
string getFirstLetterInEachWord(const string& str)
{
	// Initialize an empty string to store the result
	string result;

	// Flag to indicate if the current character is the start of a new word
	bool isNewWord = true;

	// Iterate through each character in the input string
	for (char ch : str)
	{
		if (isspace(ch))
		{
			isNewWord = true; // Next character will be the start of a new word
		}
		else if (isNewWord)
		{
			result += ch;// Append the first letter of the new word
			
			result += ' '; // Add a space after the first letter
			
			isNewWord = false; // Reset the flag
		}
	}

	// Return the result string containing the first letters of each word
	return result;
}

void printFirstLetterInEachWord(const string& result)
{
	// Print the result
	cout << "\nFirst letters of each word: " << result << endl;
}

//main function
int main()
{

	string inputString = readString(); // Read a string from the user

	string firstLetters = getFirstLetterInEachWord(inputString); // Get the first letters of each word

	printFirstLetterInEachWord(firstLetters); // Print the result

    return 0;
}
