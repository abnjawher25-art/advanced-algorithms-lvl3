#include <iostream>
#include <string>
using namespace std;

// Function to read a string from the user
string readString()
{
	string str;

	cout << "Enter a string: ";
	getline(cin, str);

	return str;
}

// Function to count the number of small and capital letters in a string
enum enLetterType
{
	SmallLetter=0,
	CapitalLetter=1,
	All=2
};

// Function to count the number of small and capital letters in a string
short countLetters(const string& str, enLetterType letterType)
{
	// Count the number of small and capital letters in a string
	short count = 0;

	short BothCases = 0;

	// Loop through the string and count the number of small and capital letters
	for (char ch : str)
	{
		if (letterType == SmallLetter && islower(ch))
		{
			count++;
		}
		else if (letterType == CapitalLetter && isupper(ch))
		{
			count++;
		}
		else if((letterType == All && islower(ch)) ||( letterType == All && isupper(ch)))
		{
			BothCases++;
		}
	}

	// Return the count of small or capital  or both case letters
	if (letterType == All)
	{
		return BothCases;
	}

	else {
		return count;
	}
		

	  
}

// Function to count the number of small letters in a string
short countSmallLetters(const string& str)
{
	// Count the number of small letters in a string
	// skip all capital letters and other characters
	return countLetters(str, SmallLetter);
}

// Function to count the number of capital letters in a string
short countCapitalLetters(const string& str)
{
	// Count the number of capital letters in a string
	// skip all small letters and other characters
	return countLetters(str, CapitalLetter);
}

//print case of letters
void printCountletters(short value , string msg)
{
	
	cout <<msg<<value<< endl;
	
}

int main()
{
	//
	enLetterType BothCases = enLetterType::All;

	string inputText = readString();

	short smlAndCapiLetters = countLetters(inputText, BothCases);

	short smallLetters = countSmallLetters(inputText);

	short CapitalLetters = countCapitalLetters(inputText);


	printCountletters(smlAndCapiLetters, "\nThe number of lower and upper cases letter is: ");


	printCountletters(smallLetters, "\nThe number of lower case letter is: ");


	printCountletters(CapitalLetters, "\nThe number of upper case letter is: ");


   return 0;
}
