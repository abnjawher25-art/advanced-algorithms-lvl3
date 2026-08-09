#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vString, string Delimiter)
{

    string collecter = "";

    for (string& str : vString)
    {
        collecter += (str + Delimiter);

    }

    return collecter.substr(0, collecter.length() - Delimiter.length());

}

string JoinString(string arr[],short length, string Delimiter)
{

    string collecter = "";

    for (short i = 0; i<length;i++)
    {
        collecter += (arr[i] + Delimiter);

    }

    return collecter.substr(0, collecter.length() - Delimiter.length());

}


int main()
{

    vector <string> vNames = { "Ebrahim","Ali","Mohammed","Salm","Fuad","Zaki" };

    string ArrNames[6] = {"Ebrahim","Ali","Mohammed","Salm","Fuad","Zaki"};

    string Text1 = JoinString(vNames, " ");

    string Text2 = JoinString(ArrNames,6, " ");

    cout << " the names after join them(vector data):" << endl;
    cout << Text1;

    cout << "\n\nthe names after join them(array data):" << endl;
    cout << Text2;

    cout << "\n\n\n" << endl;

   



    return 0;
}
