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


char readChar(string Msg)
{
    char inputChar;


    cout << Msg;
    cin >> inputChar;


    return inputChar;

}


char invertedLetter(char letter)
{

    return isupper(letter) ? tolower(letter) : toupper(letter);

}


short CountLetter(string str, char letter, bool MatchCace = true)
{
    short counter = 0;

    for (char i = 0; i < str.length(); i++)
    {
        if (MatchCace)
        {
            if (str[i] == letter)
                counter++;
        }
        else
        {
            if (tolower(str[i]) == tolower(letter))
                counter++;
        }
    }

    return counter;






}


int main()
{

    string Text = readString("Enter text : ");
    char Characher = readChar("\nEnter a characher : ");

    cout << "\nThe letter \'" << Characher << "\' count " << CountLetter(Text, Characher) << " times\n";

    cout << "\nThe letter \'" << Characher << "\' Or \'" << invertedLetter(Characher) << "\' count " << CountLetter(Text, Characher, false) << " times\n";





    return 0;
}
