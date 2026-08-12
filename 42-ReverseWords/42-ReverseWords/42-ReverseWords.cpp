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


vector <string> splitString(string str, string delimiter)
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


string ReverseWordsInString(string Text)
{
    vector <string> vWordsContainer;

    string collecter = " ";

    vWordsContainer = splitString(Text," ");

    vector<string>::iterator ItemPointer = vWordsContainer.end();

    while (ItemPointer != vWordsContainer.begin())
    {
        ItemPointer--;
        collecter += *ItemPointer + " ";
        
    }

    collecter = collecter.substr(0, collecter.length()-1);

    return collecter;
}


int main()
{
    string strInput = readString("Enter text: ");

    string reversedText = ReverseWordsInString(strInput);

    cout << "\n the origin text is: " << strInput << endl;

    cout << "\n the reverse text is: " << reversedText << endl;

    return 0;
}
