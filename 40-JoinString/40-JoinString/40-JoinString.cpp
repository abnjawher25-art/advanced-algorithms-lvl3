#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vString, string Delimiter)
{

    string collecter = "";

    for (string& str : vString)
    {
        collecter += ( str + Delimiter);

    }

    return collecter.substr(0, collecter.length() - Delimiter.length());

}


int main()
{

    vector <string> vNames = {"Ebrahim","Ali","Mohammed","Salm","Fuad","Zaki"};

    string Text = JoinString(vNames, " ");

    cout << " the names after join them: \n"<<endl;
    cout << Text;

    cout << "\nthe length of vector is : " << vNames.size();




    return 0;
}
