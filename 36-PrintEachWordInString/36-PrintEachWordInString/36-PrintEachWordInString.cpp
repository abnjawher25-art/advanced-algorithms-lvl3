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


void PrintEachWordInString(string str)
{
    string delimiter = " ";

    cout << "\nthe word in string are: \n\n";

    short position = 0;

    string StringWord ;

    while ((position = str.find(delimiter)) != std::string::npos)
    {
        StringWord = str.substr(0, position);

        if (StringWord != "")
        {
            cout << StringWord<<endl;
        }
       

        str.erase(0, position+ delimiter.length());
    }

    if (str != "")
    {
        cout << str <<endl;
    }


}


int main()
{
    
    PrintEachWordInString(readString("Enter text: "));

    return 0;
}
