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
    bool MarkForDelete = false;
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


string ConvetRecordToLine(sClient client, string seperator = "#//#")
{
    string sClientRecord = "";

    sClientRecord += client.AccountNumber + seperator;
    sClientRecord += client.PinCode + seperator;
    sClientRecord += client.Name + seperator;
    sClientRecord += client.Phone + seperator;
    sClientRecord += to_string(client.AccountBalance);

    return sClientRecord;
}


vector<sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);


    if (MyFile.is_open())
    {

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
    }

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


bool FindClientByAccountNumber(string AccountNumber, const vector<sClient>& vClients, sClient& client)
{

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


sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;


    cout << "\n\nEnter Pin Code:";
    getline(cin >> ws, Client.PinCode);


    cout << "\n\nEnter Client Name:";
    getline(cin, Client.Name);


    cout << "\n\nEnter Phone Number:";
    getline(cin, Client.Phone);


    cout << "\n\nEnter Account Balance:";
    cin >> Client.AccountBalance;


    return Client;
}


vector<sClient> SaveClientDataToFile(string FileName, const vector<sClient>& vClients)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (const sClient& C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvetRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}


bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Choice = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\nAre You Sure You Want To Update This Client? (y/n): ";
        cin >> Choice;

        if (Choice == 'y' || Choice == 'Y')
        {
            for (sClient& C : vClients)
            {

                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientDataToFile(ClientFileName, vClients);

            cout << "\n\nClient update successfully.";
            return true;

        }
    }
    else
    {
        cout << "\nThe client with account number (" << AccountNumber << ") is NOT found!";
        return false;
    }
}


int main()
{

    vector<sClient> vClients = LoadClientsDataFromFile(ClientFileName);

    string AccountNumber = readClientAccountNumber("Enter Account Number of Client: ");

    UpdateClientByAccountNumber(AccountNumber, vClients);


    cout << "\n\nPress enter key to exit...";
    system("pause>0");

    return 0;
}