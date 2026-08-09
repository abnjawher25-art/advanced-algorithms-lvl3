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

short CountEachWordInString(string str)
{
    string delimiter = " ";

    short count = 0;

    short position = 0;

    string StringWord;

    while ((position = str.find(delimiter)) != std::string::npos)
    {
        StringWord = str.substr(0, position);

        if (StringWord != "")
        {
            count++;
        }

        str.erase(0, position + delimiter.length());
    }

    if ( str != "")
    {
        count++;
    }
    
    return count;

}




int main()
{
    string strInput = readString("Enter text: ");

    short Count = CountEachWordInString(strInput);

    cout << "\nthe number of words in that string are " << Count;

    return 0;
}
