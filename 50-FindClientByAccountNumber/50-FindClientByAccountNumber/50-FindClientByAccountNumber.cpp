#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

const string ClientFileName = "Clients.txt";

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


vector<sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

   
    if (!MyFile.is_open())
    {
        MyFile.clear();
        MyFile.open(FileName, ios::out); 
        MyFile.close();
        return vClients;
    }

    string Line;
    sClient Client;

    while (getline(MyFile, Line))
    {
        if (Line != "") 
        {
            Client = ConvetLineToRecord(Line);
            vClients.push_back(Client);
        }
    }

    MyFile.close();
    return vClients;
}


void PrintClientCard(sClient Client)
{
    cout << "\nThe following are Client data:\n" << endl;
    cout << "| Account Number: " << setw(15) << left << Client.AccountNumber << endl;
    cout << "| Pin Code       : " << setw(10) << left << Client.PinCode << endl;
    cout << "| Client Name    : " << setw(40) << left << Client.Name << endl;
    cout << "| Phone Number   : " << setw(12) << left << Client.Phone << endl;
    cout << "| Account Balance: " << setw(12) << left << Client.AccountBalance << endl;
}



string readClientAccountNumber(string Msg)
{
    string AccountNumber = "";
    cout << Msg;
    cin >> AccountNumber;
    return AccountNumber;
}



bool FindClientByAccountNumber(string AccountNumber, sClient& client)
{
    
    vector<sClient> vClients = LoadClientsDataFromFile(ClientFileName);

    for (const sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            client = C;
            return true;
        }
    }

    return false;
}



int main()
{
    sClient Client;

    string AccountNumber = readClientAccountNumber("\nEnter Account Number for Client to look for: ");

    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\n\nClient with account number (" << AccountNumber << ") is not found.\n";
    }

    cout << "\n\nPress key to exit ...";
    system("pause>0");

    return 0;
}