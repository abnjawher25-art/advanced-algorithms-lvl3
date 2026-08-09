#include <iostream>
#include <string>
#include <vector>
using namespace std;


string readString(string Msg)
{
    string inputStr;

    cout << Msg;
    getline(cin, inputStr);

    return inputStr;

}


vector <string> splitString(string str,string delimiter)
{
    vector <string> vecSplitString;

    short position = 0;

    string StringWord;

    while ((position = str.find(delimiter)) != std::string::npos)
    {
        StringWord = str.substr(0, position);

        if (StringWord != "")
        {
            vecSplitString.push_back(StringWord);
        }

        str.erase(0, position + delimiter.length());
    }

    if (str != "")
    {
        vecSplitString.push_back(StringWord);
    }

    return vecSplitString;

}

void PrintVectorElement(vector <string> elements)
{
    cout << endl;

    for (string& item : elements)
    {
        cout << item << endl;
    }
}


int main()
{
    string strInput = readString("Enter text: ");

    vector <string> vSplitString = splitString( strInput, " ");

    PrintVectorElement(vSplitString);

    return 0;
}
