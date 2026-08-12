#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0.0;
};


vector<string> splitString(string str, string delimiter)
{
    vector<string> vecSplitString;
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
        vecSplitString.push_back(str);
    }

    return vecSplitString;
}


sClient ConvetLineToRecord(string Line, string seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = splitString(Line, seperator);

   
    if (vClientData.size() >= 5)
    {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }

    return Client;
}


void PrintClientRecord(sClient Client)
{
    cout << "\n\nThe following are Client data:\n" << endl;
    cout << "The Account Number is      : " << Client.AccountNumber << endl;
    cout << "The Pin Code is            : " << Client.PinCode << endl;
    cout << "The Client Name is         : " << Client.Name << endl;
    cout << "The Client Phone Number is : " << Client.Phone << endl;
    cout << "The Account Balance is     : " << Client.AccountBalance << endl;
}


int main()
{
    string ClientData = "E884#//#8008#//#Ebrahim Bin-Goher#//#739758085#//#154847.000000";

    cout << "Data Client Line is:\n";
    cout << ClientData;

    sClient NewClient = ConvetLineToRecord(ClientData);

    PrintClientRecord(NewClient);

    cout << "\n\nPress key to exit...";
    system("pause>0");

    return 0;
}