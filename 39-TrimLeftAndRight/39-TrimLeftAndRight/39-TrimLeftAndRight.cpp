#include <iostream>
#include <string>
using namespace std;


string TrimLeft(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(i, Text.length() - 1);
		}

	}

	return " ";
}


string TrimRight(string Text)
{
	for (short i = Text.length() - 1 ; i >= 0; i--)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(0 , i + 1 );
		}

	}

	return " ";
}


string Trim(string Text)
{

	return TrimLeft(TrimRight(Text));
}



int main()
{
	string str = "      Ebrahim Bin-Goher      ";

	cout << " the text value: " << str << endl;

	cout << "\n trim left: " << TrimLeft(str) << endl;

	cout << "\n trim right: " << TrimRight(str) << endl;

	cout << "\n trim: " << Trim(str) << endl;






   return 0;
}
