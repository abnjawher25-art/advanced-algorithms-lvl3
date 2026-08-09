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


char readCharacher(string Msg)
{
    char inputChar;

    cout<< Msg;
    cin>> inputChar;

    return inputChar;
}


short countCharacherInText(string& str, char &inputChar)
{
    short count = 0;

    for (char& i : str)
    {
        if (i == inputChar)
        {
            count++;
        }
    }

    return count;


}


void printCountLetterInText(const string& str, char& inputChar, short count)
{

    if (count > 0) 
    {
        cout << "\nthe letter " << inputChar << " repeated " << count << " times.";
    }
    else 
    {
        cout << "\nthe letter is not in text.\n";
    }
  
}


int main()
{

    string inputText = readString("Enter a text : ");

    char inputChar = readCharacher("Enter characher to count it : ");

    short countTimes = countCharacherInText(inputText, inputChar);

    printCountLetterInText(inputText, inputChar, countTimes);




    return 0;
}

