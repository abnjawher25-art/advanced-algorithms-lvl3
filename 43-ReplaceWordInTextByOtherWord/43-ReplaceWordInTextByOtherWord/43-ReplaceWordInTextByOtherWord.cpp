#include <iostream>
#include <string>
using namespace std;


string replacewordsInStrings(string str, string toReplace, string replaceTo)
{
	short position = str.find(toReplace);

	while (position != std::string::npos)
	{
		str = str.replace(position, toReplace.length(), replaceTo);

		position = str.find(toReplace);
	}

	return str;

}


int main()
{
	string Text = "Ebrahim improve his skills in programming.";
	string toReplace = "Ebrahim";
	string rplaceTo = "Ali";

	string result = replacewordsInStrings(Text, toReplace, rplaceTo);

	cout << "The Origin Text Is: " << Text << endl;
	cout << "\nThe Modified Text Is: " << result << endl;
	


   return 0;
}
