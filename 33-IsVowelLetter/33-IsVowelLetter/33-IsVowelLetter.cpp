#include <iostream>
#include <string>
using namespace std;


char readChar(string Msg)
{
	char inputChar;

	cout << Msg;
	cin >> inputChar;


	return inputChar;

}


bool isVowelLetter(char Characher)
{
	char letter = tolower(Characher);
	return (letter == 'a' || letter == 'e' ||
		letter == 'i' || letter == 'o' || letter == 'u');

}


void PrintVowelResult(char Characher, bool rasult)
{

	if (rasult == true)
	{
		cout << "\nthe letter '" << Characher << "' is a vowel letter.\n";
    }
	else 
	{
		cout << "\nthe letter " << Characher << " is not a vowel letter.\n";
	}

}


int main()
{

	char inputLetter = readChar("Enter letter to check if vowel or not: ");

	bool result = isVowelLetter(inputLetter);


	PrintVowelResult(inputLetter, result);

   return 0 ;
}
