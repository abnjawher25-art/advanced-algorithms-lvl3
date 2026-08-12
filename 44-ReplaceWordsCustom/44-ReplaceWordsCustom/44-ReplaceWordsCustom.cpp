#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>splitString(string str, string delimiter)
{
    vector<string> vString;

    short position = 0;

    string sWord;

    while ((position = str.find(delimiter)) != std::string::npos)
    {
        sWord = str.substr(0, position);

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        str.erase(0, position + delimiter.length());

    }

    if (str != "")
    {
        vString.push_back(sWord);
    }

    return vString;
}


string JoinString(vector<string> vString, string delimiter)
{
    string str;

    for (string& S : vString)
    {
        str += (S + delimiter);
    }

    return str.substr(0, str.length() - delimiter.length());
}


string LowerAllLetters(string str)
{
    for (short L = 0; L < str.length(); L++)
    {
        str[L] = tolower(L);
    }

    return str;
}


string replaceWordsInStringUsingSplit(string str, string toReplace, string ReplaceTo, bool MatchCace = true)
{

    vector<string> Vstring = splitString(str, " ");

    for (string& S : Vstring)
    {
        if (MatchCace)
        {
            if (S == toReplace)
            {
                S = ReplaceTo;
            }
        }
        else
        {
            if (LowerAllLetters(S) == LowerAllLetters(toReplace))
            {
                S = ReplaceTo;
            }

        }

    }

    return JoinString(Vstring, " ");

}


int main()
{
    string text = "Ebrahim lives in KSA , KSA is worse country.";
    string toReplace = "KSA";
    string replaceTo = "Yemen";

    cout << "Origin Text is: "<< text << endl;


    cout << "\nReplace By MatchCace: "<< replaceWordsInStringUsingSplit(text, toReplace, replaceTo) << endl;
   
    
    cout << "\nReplace without MatchCace: "<< replaceWordsInStringUsingSplit(text, toReplace, replaceTo,false) << endl;


    return 0;
}

