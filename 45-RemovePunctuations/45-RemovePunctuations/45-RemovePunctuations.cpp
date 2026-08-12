#include <iostream>
#include <string>
using namespace std;

string RemovePunctuationInString(string str)
{
	string strValue = "";

	for (short L = 0; L < str.length(); L++)
	{
		if (!ispunct(str[L]))
		{
			strValue += str[L];
		}
	}

	return strValue;

}


int main()
{

	string text = "Hi! I'm Ebrahim .\nHow Are You ?";

	string ClearText = RemovePunctuationInString(text);

	cout << "\nThe Origin Text: \n" << text << endl;

	cout << "\nThe text after pick punctuations: \n" << ClearText<<endl;


    return 0 ;
}

