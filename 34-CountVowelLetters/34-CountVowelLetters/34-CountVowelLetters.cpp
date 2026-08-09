#include <iostream>
#include <string>
using namespace std;


string readString(string Msg)
{
	string inputStr;

	cout << Msg;
	getline(cin,inputStr);


	return inputStr;

}


bool isVowelLetter(char Characher)
{
	char letter = tolower(Characher);
	return (letter == 'a' || letter == 'e' ||
		letter == 'i' || letter == 'o' || letter == 'u');

}


short CountVowelLetters(string InpText)
{
	short count = 0;

	for (char L : InpText)
	{
		if (isVowelLetter(L))
			count++;

	}
	return count;
}


void PrintCountVowelLetters(short count)
{
	(count > 0) ? cout << "\nNumber of vowel letters is " << count<<"\n" : cout << "\nNo Vowel Letters\n";

}


int main()
{

	string inputText = readString("Enter Text to check if vowel or not: ");


	short count = CountVowelLetters(inputText);


	PrintCountVowelLetters(count);
	

	return 0;
}
