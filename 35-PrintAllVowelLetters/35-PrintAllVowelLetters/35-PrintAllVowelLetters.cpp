#include <iostream>
#include <string>
using namespace std;


string readString(string Msg)
{
	string inputStr;

	cout << Msg;
	getline(cin, inputStr);


	return inputStr;

}


bool isVowelLetter(char Characher)
{
	char letter = tolower(Characher);
	return (letter == 'a' || letter == 'e' ||
		letter == 'i' || letter == 'o' || letter == 'u');

}


void PrintVowelLetters(string InpText)
{
	cout << "\nVowels in string are:" << endl;
	for (char L : InpText)
	{
		if (isVowelLetter(L))
			cout<<L<<"  ";

	}
	
}


int main()
{

	string inputText = readString("Enter Text to check if vowel or not: ");

	PrintVowelLetters(inputText);



	


	return 0;
}
